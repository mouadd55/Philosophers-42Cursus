/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:40:23 by moudrib           #+#    #+#             */
/*   Updated: 2023/05/23 23:26:13 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
 
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>

typedef struct s_info
{
       int                             meal;
       sem_t                   *print;
       sem_t                   *forks;
       sem_t                   *update_value;
       int                             philo_id;
       size_t                  time_to_die;
       size_t                  time_to_eat;
       size_t                  time_to_sleep;
       size_t                  last_time_to_eat;
       size_t                  start_of_the_program;
       int                             number_of_meals;
       int                             number_of_philos;
       struct s_info   *next;
}      t_info;

/********************************** Parsing ***********************************/
void		ft_error(int error);
int			ft_strlen(char *str);
int			ft_limits(char *arg);
ssize_t		ft_atoi(const char *str);
int			ft_count_words(char *str);
int         ft_check_digit(char **av, t_info *info);

/************************************ Utils ***********************************/

size_t		ft_current_time(void);
void		ft_sleep(size_t melliseconds);

#endif