/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:52:13 by moudrib           #+#    #+#             */
/*   Updated: 2023/05/28 21:53:05 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_number_of_meals(void *infos)
{
	int		i;
	t_info	*info;

	i = 0;
	info = (t_info *)infos;
	while (i < info->number_of_philos)
	{
		sem_wait(info->meals);
		i++;
	}
	sem_wait(info->print);
	printf("\e[33mPhilosophers: Pleeeeease just one another meal.\e[0m\n");
	exit(1);
}

void	*ft_check_death(void *infos)
{
	t_info	*info;

	info = (t_info *)infos;
	while (1)
	{
		sem_wait(info->update_value);
		if (ft_current_time() - info->last_time_to_eat > info->time_to_die)
		{
			sem_wait(info->print);
			printf("\e[91m%lu %d died\e[0m\n", ft_current_time()
				- info->start_of_the_program, info->philo_id);
			exit(1);
		}
		sem_post(info->update_value);
	}
}

pid_t	*ft_create_processes(int number_of_philos, t_info *info)
{
	int			i;
	pid_t		*pids;

	i = 0;
	pids = malloc (sizeof(pid_t) * number_of_philos);
	if (!pids)
		return (0);
	while (i < number_of_philos)
	{
		info->last_time_to_eat = ft_current_time();
		pids[i] = fork();
		if (pids[i] == 0)
		{
			info->philo_id = i + 1;
			ft_philosopher_actions(info);
		}
		else if (pids[i] < 0)
			return (0);
		i++;
	}
	return (pids);
}

int	main(int ac, char **av)
{
	t_info		info;
	pthread_t	thread2;

	if (ac < 5)
		ft_error(1);
	else if (ac > 6)
		ft_error(2);
	info.number_of_philos = ft_check_digit(av, &info);
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("update_value");
	sem_unlink("meals");
	info.print = sem_open("print", O_CREAT, 0644, 1);
	info.update_value = sem_open("update_value", O_CREAT, 0644, 1);
	info.forks = sem_open("forks", O_CREAT, 0644, info.number_of_philos);
	info.meals = sem_open("meals", O_CREAT, 0644, 0);
	info.start_of_the_program = ft_current_time();
	pthread_create(&thread2, NULL, ft_check_number_of_meals, &info);
	ft_create_processes(info.number_of_philos, &info);
	waitpid(0, NULL, 0);
	kill(0, SIGINT);
	return (0);
}
