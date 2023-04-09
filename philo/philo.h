/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:22:57 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/09 18:26:35 by moudrib          ###   ########.fr       */
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
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_time_to_eat;
	int				eat_again;
	int				number_of_times_each_philosopher_must_eat;
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

#endif