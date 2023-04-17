/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:52:13 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/17 20:11:09 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

pid_t	*ft_create_processes(int number_of_philos)
{
	int		i;
	pid_t	*pids;
	
	pids = malloc (sizeof(pid_t) * number_of_philos);
	if (!pids)
		return (0);
	for (i = 0; i < number_of_philos; i++)
	{
        pids[i] = fork();
        // printf(">%d<\n", pids[i]);
		if (pids[i] == 0)
		{
            // This is the child process
            printf("Child process %d executing... \n", i);
			
            // Child process should exit to avoid running the same code as the parent
            return (0);
        }
		else if (pids[i] < 0)
		{
            // Fork failed
            perror("fork");
            return (0);
        }
        // This is the parent process
        printf("Parent process executing, created child process %d with PID %d\n", i, pids[i]);
    }
    // Wait for all child processes to finish
    for (i = 0; i < number_of_philos; i++)
        wait(NULL);
	return (pids);
}

int	main(int ac, char **av)
{
	pid_t	*pids;
	int		number_of_philos;

	if (ac < 5)
		ft_error(1);
	else if (ac > 6)
		ft_error(2);
	number_of_philos = ft_check_digit(av);
	pids = ft_create_processes(number_of_philos);
	for (int i = 0; i < number_of_philos; i++)
		printf("|%d|\n", pids[i]);
    return 0;
}
