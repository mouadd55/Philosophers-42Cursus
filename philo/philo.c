/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:26:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/14 01:39:36 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_number_of_meals(int number_of_philos, t_list *philosophers)
{
	int		i;
	int		count;
	t_list	*tmp;

	i = 0;
	count = 0;
	tmp = philosophers;
	while (i++ < number_of_philos)
	{
		pthread_mutex_lock(&tmp->update_value);
		if (tmp->meal == philosophers->number_of_meals)
			count++;
		pthread_mutex_unlock(&tmp->update_value);
		tmp = tmp->next;
	}
	if (count == number_of_philos)
		return (1);
	return (0);
}

int	ft_check_death(t_list *philosophers, t_list *tmp)
{
	pthread_mutex_lock(&tmp->update_value);
	if (ft_current_time() - tmp->last_time_to_eat > philosophers->time_to_die)
	{
		pthread_mutex_lock(philosophers->print);
		printf("\e[91m%lu %d died\n\e[0m", ft_current_time()
			- philosophers->start_of_the_program, tmp->philo_id);
		return (1);
	}
	pthread_mutex_unlock(&tmp->update_value);
	return (0);
}

t_list	*ft_init_mutexes(int number_of_philos, t_list *philosophers)
{
	int				i;
	t_list			*tmp;
	pthread_mutex_t	*print;

	print = malloc(sizeof(pthread_mutex_t));
	if (!print)
		return (NULL);
	pthread_mutex_init(print, 0);
	i = -1;
	tmp = philosophers;
	while (++i < number_of_philos)
	{
		tmp->print = print;
		pthread_mutex_init(&tmp->fork, 0);
		pthread_mutex_init(&tmp->update_value, 0);
		tmp = tmp->next;
	}
	return (philosophers);
}

void	*ft_create_threads(int number_of_philos, t_list **philosophers)
{
	int			i;
	t_list		*tmp;
	pthread_t	*threads;

	i = -1;
	threads = malloc(sizeof(pthread_t) * number_of_philos);
	if (!threads)
		return (NULL);
	tmp = ft_init_mutexes(number_of_philos, *philosophers);
	while (++i < number_of_philos)
	{
		pthread_create(&threads[i], NULL, ft_philosopher_actions, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < number_of_philos)
		pthread_detach(threads[i]);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*tmp;
	t_list	*philosophers;
	int		number_of_philos;

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
		if (ft_check_death(philosophers, tmp))
			return (0);
		else if (tmp->number_of_meals
			&& ft_check_number_of_meals(number_of_philos, philosophers))
		{
			pthread_mutex_lock(philosophers->print);
			printf("\e[33mPhilosophers: Pleeeeease just one another meal.\n");
			return (0);
		}	
		tmp = tmp->next;
	}
}
