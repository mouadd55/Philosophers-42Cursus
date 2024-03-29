/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:22:57 by moudrib           #+#    #+#             */
/*   Updated: 2023/06/17 13:04:25 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_list
{
	int				meal;
	int				philo_id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_meals;
	size_t			last_time_to_eat;
	size_t			start_of_the_program;
	pthread_mutex_t	fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	update_value;
	struct s_list	*next;
}	t_list;

/********************************** Parsing ***********************************/
int			ft_strlen(char *str);
int			ft_limits(char *arg);
ssize_t		ft_atoi(const char *str);
int			ft_count_words(char *str);
int			ft_check_digit(char **av, int *number_of_philos);
int			ft_error(int ac, int error);

/********************************* List utils *********************************/

t_list		*ft_lstlast(t_list *head);
t_list		*ft_lstnew(int id, int ac, char **av);
void		ft_lstadd_back(t_list **head, t_list *new);
void		*ft_destroy_list(t_list **head, int number_of_philos);
void		ft_create_list(int philos, t_list **list, int ac, char **av);

/************************************ Utils ***********************************/

size_t		ft_current_time(void);
void		ft_sleep(size_t melliseconds);

/************************** Routine of philosophers ***************************/

void		*ft_philosopher_actions(void *list);
void		philosopher_is_eating(t_list *philosophers);
void		philosopher_is_sleeping_and_thinking(t_list *philosophers);

#endif