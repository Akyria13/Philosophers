/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:47:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/18 16:49:39 by jowagner         ###   ########.fr       */
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
			printf("Argument must be a number.\n");
			return (false);
		}
		i++;
	}
	return (true);
}
