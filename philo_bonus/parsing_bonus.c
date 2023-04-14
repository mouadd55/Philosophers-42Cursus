/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:41:21 by moudrib           #+#    #+#             */
/*   Updated: 2023/04/13 18:41:28 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(int error)
{
	if (error == 1)
		printf("\e[31m\e[1mError:\e[0m \e[1mTo few arguments.\n");
	else if (error == 2)
		printf("\e[31m\e[1mError:\e[0m \e[1mTo many arguments.\n");
	if (error == 3)
		printf("\e[31m\e[1mError:\e[0m \e[1mInvalid arguments.\n");
	else if (error == 4)
		printf("\e[31m\e[1mError:\e[0m \e[1mShould be at least one philosopher.\n");
	exit(1);
}

int	ft_limits(char *arg)
{
	int	i;

	i = -1;
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < 0)
		return (1);
	return (0);
}

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

int	ft_check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		if (!ft_count_words(av[i]) || (ft_strlen(av[i]) == 1
				&& av[i][0] == '+') || ft_limits(av[i]))
			ft_error(3);
		if (ft_atoi(av[1]) == 0)
			ft_error(4);
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
			if (!(av[i][j] >= '0' && av[i][j++] <= '9'))
				ft_error(3);
	}
	return (ft_atoi(av[1]));
}
