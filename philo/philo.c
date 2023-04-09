/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:26:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/09 18:28:12 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_is_thinking(t_list *philosophers, int *timestamp)
{
	pthread_mutex_lock(&philosophers->print);
	printf("%d %d is thinking\n", *timestamp, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
	philosophers->eat_again = ft_current_time();
}

void	philosopher_is_sleeping(t_list *philosophers, int *timestamp)
{
	pthread_mutex_lock(&philosophers->print);
	printf("%d %d is sleeping\n", *timestamp, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
	ft_sleep(philosophers->time_to_sleep);
	*timestamp += philosophers->time_to_sleep;
}

void	philosopher_is_eating(t_list *philosophers, int *timestamp)
{
	pthread_mutex_lock(&philosophers->fork);
	pthread_mutex_lock(&philosophers->next->fork);
	pthread_mutex_lock(&philosophers->print);
	printf("%d %d has taken a fork\n", *timestamp, philosophers->philo_id);
	philosophers->last_time_to_eat = ft_current_time();
	printf("%d %d is eating\n", *timestamp, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
	ft_sleep(philosophers->time_to_eat);
	*timestamp += philosophers->time_to_eat;
	pthread_mutex_unlock(&philosophers->fork);
	pthread_mutex_unlock(&philosophers->next->fork);
}

void	*ft_philosopher_actions(void *list)
{
	t_list		*philosophers;
	static int	timestamp;

	philosophers = (t_list *)list;
	if (philosophers->philo_id % 2 == 0)
		ft_sleep(100);
	while (1)
	{
		philosopher_is_eating(philosophers, &timestamp);
		usleep(100);
		philosopher_is_sleeping(philosophers, &timestamp);
		philosopher_is_thinking(philosophers, &timestamp);
	}
	return (0);
}

void	ft_create_list(int number_of_philos, t_list **list, int ac, char **av)
{
	int		id;
	t_list	*tmp;

	id = 0;
	while (++id <= number_of_philos)
		ft_lstadd_back(list, ft_lstnew(id, ac, av));
	tmp = ft_lstlast(*list);
	tmp->next = *list;
}

void	ft_create_threads(int number_of_philos, t_list **philosophers)
{
	int			i;
	t_list		*tmp;
	pthread_t	*threads;

	i = -1;
	tmp = *philosophers;
	threads = malloc(sizeof(pthread_t) * number_of_philos);
	while (++i < number_of_philos)
	{
		pthread_mutex_init(&tmp->fork, 0);
		pthread_mutex_init(&tmp->print, 0);
		pthread_create(&threads[i], NULL, ft_philosopher_actions, tmp);
		pthread_detach(threads[i]);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	int		number_of_philos;
	t_list	*tmp;
	t_list	*philosophers;

	if (ac < 5)
		ft_error(1);
	else if (ac > 6)
		ft_error(2);
	number_of_philos = ft_check_digit(av);
	ft_create_list(number_of_philos, &philosophers, ac, av);
	ft_create_threads(number_of_philos, &philosophers);
	tmp = philosophers;
	while (1)
	{
		if (tmp->eat_again && tmp->last_time_to_eat && (tmp->eat_again
				- tmp->last_time_to_eat) > philosophers->time_to_die)
		{
			printf("%d %d\n", tmp->eat_again, tmp->last_time_to_eat);
			printf("%d died\n", tmp->philo_id);
			exit(0);
		}
		tmp = tmp->next;
	}
	return (0);
}
