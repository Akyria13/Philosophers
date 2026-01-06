/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/06 14:29:09 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_die, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_eat, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_print, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_stop, NULL) != 0)
		return (false);
	return (true);
}

bool	init_data(t_data *data, int ac, char **av)
{
	data->start_time = 0;
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_meal = ft_atoi(av[5]);
	else
		data->nbr_meal = -1;
	if (!init_mutex(data))
		return (false);
	return (true);
}

bool	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].is_alive = true;
		philo[i].is_eating = false;
		philo[i].is_thinking = false;
		philo[i].fork_left = &data->fork[i];
		philo[i].fork_right = &data->fork[(i + 1) % data->nbr_philo];
		if (pthread_mutex_init(&philo[i].mutex, NULL) != 0)
			return (false);
	}
	return (true);
}

bool	init_fork(t_data *data, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		fork[i].id = i;
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}
