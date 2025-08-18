/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/18 18:42:30 by jowagner         ###   ########.fr       */
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
	data->nbr_philo = str_to_int(av[1]);
	data->nbr_meal = 0;
	if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
		return (false);
	return (true);
}
