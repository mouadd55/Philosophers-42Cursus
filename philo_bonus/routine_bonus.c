/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:52:23 by moudrib           #+#    #+#             */
/*   Updated: 2023/06/05 11:30:56 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philosopher_is_sleeping_and_thinking(t_info *info)
{
	sem_post(info->forks);
	sem_post(info->forks);
	sem_wait(info->print);
	printf("%7lu | Philosopher: %d is sleeping 💤\n",
		ft_current_time() - info->start_of_the_program, info->philo_id);
	sem_post(info->print);
	ft_sleep(info->time_to_sleep);
	sem_wait(info->print);
	printf("%7lu | Philosopher: %d is thinking 🤔\n",
		ft_current_time() - info->start_of_the_program, info->philo_id);
	sem_post(info->print);
}

void	philosopher_is_eating(t_info *info)
{
	sem_wait(info->forks);
	sem_wait(info->print);
	printf("\e[1m%7lu | Philosopher: %d has taken a fork 🍴\n",
		ft_current_time() - info->start_of_the_program, info->philo_id);
	sem_post(info->print);
	sem_wait(info->forks);
	sem_wait(info->print);
	printf("\e[1m%7lu | Philosopher: %d has taken a fork 🍴\n",
		ft_current_time() - info->start_of_the_program, info->philo_id);
	sem_post(info->print);
	sem_wait(info->print);
	printf("%7lu | Philosopher: %d is eating 🍝\n",
		ft_current_time() - info->start_of_the_program, info->philo_id);
	sem_post(info->print);
	sem_wait(info->update_value);
	info->last_time_to_eat = ft_current_time();
	sem_post(info->update_value);
	ft_sleep(info->time_to_eat);
	sem_wait(info->update_value);
	info->meal++;
	sem_post(info->update_value);
	sem_wait(info->update_value);
	if (info->meal == info->number_of_meals)
		sem_post(info->meals);
	sem_post(info->update_value);
}

void	*ft_philosopher_actions(void *infos)
{
	t_info		*info;
	pthread_t	thread1;

	info = (t_info *)infos;
	pthread_create(&thread1, NULL, ft_check_death, info);
	pthread_detach(thread1);
	while (1)
	{
		philosopher_is_eating(info);
		philosopher_is_sleeping_and_thinking(info);
	}
	return (0);
}
