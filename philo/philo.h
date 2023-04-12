/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:22:57 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/12 10:31:51 by moudrib          ###   ########.fr       */
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
	pthread_mutex_t	fork;
	pthread_mutex_t	print;
	pthread_mutex_t	update_value;
	int				philo_id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_time_to_eat;
	size_t			start_of_the_program;
	int				num_of_meals;
	struct s_list	*next;
}	t_list;

int			ft_strlen(char *str);
int			ft_limits(char *arg);
ssize_t		ft_atoi(const char *str);
int			ft_count_words(char *str);
int			ft_check_digit(char **av);
void		ft_error(int error);

t_list		*ft_lstnew(int id, int ac, char **av);
t_list		*ft_lstlast(t_list *head);
int			ft_count_nodes(t_list *head);
void		*ft_destroy_list(t_list **head);
void		ft_lstadd_back(t_list **head, t_list *new);

void		*ft_philosopher_actions(void *list);
size_t		ft_current_time(void);
void		ft_sleep(size_t melliseconds);

void		philosopher_is_thinking(t_list *philosophers);
void		philosopher_is_sleeping(t_list *philosophers);
void		philosopher_is_eating(t_list *philosophers);
void		*ft_philosopher_actions(void *list);

#endif