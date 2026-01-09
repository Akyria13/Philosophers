/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:47:43 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/09 15:04:16 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			return (false);
		}
		if (i == 5 && ft_atoi(av[i]) == 0)
		{
			printf("Nothing to eat.\n");
			return (false);
		}
		if (ft_atoi(av[i]) >= INT_MAX
			|| ft_atoi(av[i]) < 0)
		{
			printf("Number must be in range of 1 and INT_MAX.\n");
			return (false);
		}
		i++;
	}
	return (true);
}
