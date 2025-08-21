/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/21 15:24:12 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*cacaprout(void *arg)
{
	printf("salut je suis %s\n", (char *)arg);
	return (NULL);
}

void	init_thread(t_data *data)
{
	t_philo *philo;
	// int		i;

	philo = data->philo;
	// i = 0;
	// while (i < data->nbr_philo)
	if (pthread_create(&philo->thread, NULL, cacaprout, "1") != 0)
	{
		printf("error");
	}
}

bool	init_struct(t_data *data, char **av)
{
	data->philo = calloc(0, sizeof(*data->philo));
	if (!data->philo)
		return (false);
	data->nbr_philo = ft_atoi(av[1]);
	data->nbr_meal = 0;
	if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
		return (false);
	return (true);
}
