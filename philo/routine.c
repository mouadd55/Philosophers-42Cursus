/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:49:29 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/12 10:33:28 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_is_thinking(t_list *philosophers)
{
	pthread_mutex_lock(&philosophers->print);
	printf("%lu %d is thinking\n", ft_current_time()
		- philosophers->start_of_the_program, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
}

void	philosopher_is_sleeping(t_list *philosophers)
{
	pthread_mutex_lock(&philosophers->print);
	printf("%lu %d is sleeping\n", ft_current_time()
		- philosophers->start_of_the_program, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
	ft_sleep(philosophers->time_to_sleep);
}

void	philosopher_is_eating(t_list *philosophers)
{
	pthread_mutex_lock(&philosophers->fork);
	pthread_mutex_lock(&philosophers->next->fork);
	pthread_mutex_lock(&philosophers->print);
	printf("%lu %d has taken a fork\n", ft_current_time()
		- philosophers->start_of_the_program, philosophers->philo_id);
	printf("%lu %d is eating\n", ft_current_time()
		- philosophers->start_of_the_program, philosophers->philo_id);
	pthread_mutex_unlock(&philosophers->print);
	pthread_mutex_lock(&philosophers->update_value);
	philosophers->last_time_to_eat = ft_current_time();
	pthread_mutex_unlock(&philosophers->update_value);
	ft_sleep(philosophers->time_to_eat);
	pthread_mutex_unlock(&philosophers->fork);
	pthread_mutex_unlock(&philosophers->next->fork);
}

void	*ft_philosopher_actions(void *list)
{
	t_list	*philosophers;

	philosophers = (t_list *)list;
	if (philosophers->philo_id % 2 == 0)
		ft_sleep(100);
	while (1)
	{
		philosopher_is_eating(philosophers);
		philosopher_is_sleeping(philosophers);
		philosopher_is_thinking(philosophers);
	}
	return (0);
}
