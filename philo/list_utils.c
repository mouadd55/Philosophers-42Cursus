/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:24:12 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/12 10:32:45 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(int id, int ac, char **av)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->philo_id = id;
	node->time_to_die = ft_atoi(av[2]);
	node->time_to_eat = ft_atoi(av[3]);
	node->time_to_sleep = ft_atoi(av[4]);
	node->last_time_to_eat = 0;
	node->start_of_the_program = ft_current_time();
	if (ac == 6)
		node->num_of_meals = ft_atoi(av[5]);
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!*head || !head)
		*head = new;
	else
	{
		tmp = ft_lstlast(*head);
		tmp->next = new;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (!head->next)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	*ft_destroy_list(t_list **head)
{
	t_list	*tmp;

	if (!head || !*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		free (*head);
		(*head) = tmp;
	}
	return (0);
}

int	ft_count_nodes(t_list *head)
{
	t_list	*tmp;
	t_list	*start;
	int		count;

	count = 0;
	if (!head)
		return (0);
	else
		count++;
	tmp = head;
	start = head;
	while (tmp)
	{
		if (tmp->next == start)
			break ;
		count++;
		tmp = tmp->next;
	}
	return (count);
}
