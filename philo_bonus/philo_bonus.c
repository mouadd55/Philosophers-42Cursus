/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:52:13 by moudrib           #+#    #+#             */
/*   Updated: 2023/05/23 23:33:32 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int    ft_check_number_of_meals(int number_of_philos, t_info *info)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	sem_wait(info->update_value);
	if (info->meal == info->number_of_meals)
		count++;
	sem_post(info->update_value);
	if (count == number_of_philos)
	{
		printf("1111\n");
		sem_wait(info->print);
		printf("\e[33mPhilosophers: Pleeeeease just one another meal.\e[0m\n");
		return (1);
	}
	return (0);
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
		else if (info->number_of_meals
			&& ft_check_number_of_meals(info->number_of_philos, info))
			exit(1);
		sem_post(info->update_value);
	}
}

void	*ft_philosopher_actions(void *infos)
{
	t_info		*info;
	pthread_t	thread;

	info = (t_info *)infos;
	if (info->philo_id % 2 == 0)
		ft_sleep(100);
	pthread_create(&thread, NULL, ft_check_death, info);
	while (1)
	{
		sem_wait(info->forks);
		sem_wait(info->print);
		printf("\e[1m%7lu | Philosopher: %d has taken a fork 🍴\n", ft_current_time()
		- info->start_of_the_program, info->philo_id);
		sem_post(info->print);
		sem_wait(info->forks);
		sem_wait(info->print);
		printf("\e[1m%7lu | Philosopher: %d has taken a fork 🍴\n", ft_current_time()
		- info->start_of_the_program, info->philo_id);
		sem_post(info->print);
		sem_wait(info->print);
		printf("%7lu | Philosopher: %d is eating 🍝\n", ft_current_time()
		- info->start_of_the_program, info->philo_id);
		sem_post(info->print);
		sem_wait(info->update_value);
		info->last_time_to_eat = ft_current_time();
		sem_post(info->update_value);
		ft_sleep(info->time_to_eat);

		sem_wait(info->update_value);
		info->meal++;
		sem_post(info->update_value);

		sem_post(info->forks);
		sem_post(info->forks);
		sem_wait(info->print);
		printf("%7lu | Philosopher: %d is sleeping 💤\n", ft_current_time()
		- info->start_of_the_program, info->philo_id);
		sem_post(info->print);
		ft_sleep(info->time_to_sleep);
		sem_wait(info->print);
		printf("%7lu | Philosopher: %d is thinking 🤔\n", ft_current_time()
		- info->start_of_the_program, info->philo_id);
		sem_post(info->print);
	}
	return (0);
}

pid_t	*ft_create_processes(int number_of_philos, t_info *info)
{
	int			i;
	pid_t		*pids;

	pids = malloc (sizeof(pid_t) * number_of_philos);
	if (!pids)
		return (0);
	info->last_time_to_eat = ft_current_time();
	for (i = 0; i < number_of_philos; i++)
	{
        pids[i] = fork();
		if (pids[i] == 0)
		{
			info->philo_id = i + 1;
			ft_philosopher_actions(info);
        }
		else if (pids[i] < 0)
            return (0);
    }
	return (pids);
}

int	main(int ac, char **av)
{
	pid_t		*pids;
	t_info		info;

	if (ac < 5)
		ft_error(1);
	else if (ac > 6)
		ft_error(2);
	info.number_of_philos = ft_check_digit(av, &info);
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("update_value");
	info.print = sem_open("print", O_CREAT, 0644, 1);
	info.print = sem_open("update_value", O_CREAT, 0644, 1);
	info.forks = sem_open("forks", O_CREAT, 0644, info.number_of_philos);
	info.start_of_the_program = ft_current_time();
	pids = ft_create_processes(info.number_of_philos, &info);
	waitpid(0, NULL , 0);
	kill(0, SIGINT);
    return 0;
}
