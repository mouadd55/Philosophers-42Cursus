/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:26:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/12 17:15:16 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_list *philosophers, t_list *tmp)
{
	pthread_mutex_lock(&tmp->update_value);
	if (ft_current_time() - tmp->last_time_to_eat > philosophers->time_to_die)
	{
		pthread_mutex_lock(philosophers->print);
		printf("%lu %d died\n", ft_current_time()
			- philosophers->start_of_the_program, tmp->philo_id);
		return (1);
	}
	// else if ()
	pthread_mutex_unlock(&tmp->update_value);
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
	pthread_mutex_t	*print;

	i = -1;
	tmp = *philosophers;
	threads = malloc(sizeof(pthread_t) * number_of_philos);
	print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, 0);
	while (++i < number_of_philos)
	{
		tmp->print = print;
		pthread_mutex_init(&tmp->fork, 0);
		pthread_mutex_init(&tmp->update_value, 0);
		tmp = tmp->next;
	}
	i = -1;
	tmp = *philosophers;
	while(++i < number_of_philos)
	{
		pthread_create(&threads[i], NULL, ft_philosopher_actions, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while(++i < number_of_philos)
		pthread_detach(threads[i]);
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
		if (ft_check_death(philosophers, tmp))
			return (0);
		tmp = tmp->next;
	}
	return (0);
}
