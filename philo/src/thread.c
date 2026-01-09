/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/09 14:52:20 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_meals(t_data *data)
{
	int	i;
	int	philo_full;

	i = 0;
	philo_full = 0;
	if (data->nbr_meal <= 0)
		return (false);
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->philo[i].mutex);
		if (data->philo[i].meals_eaten >= data->nbr_meal)
			philo_full++;
		pthread_mutex_unlock(&data->philo[i].mutex);
		i++;
	}
	return (philo_full == data->nbr_philo);
}

static bool	check_death(t_data *data, int i)
{
	long	current_time;
	long	last_meal;

	current_time = ft_time(data);
	pthread_mutex_lock(&data->philo[i].mutex);
	last_meal = data->philo[i].last_meal;
	pthread_mutex_unlock(&data->philo[i].mutex);
	if (current_time - last_meal > data->time_to_die)
	{
		print_activities(DEAD, &data->philo[i]);
		pthread_mutex_lock(&data->lock_stop);
		data->simulation_stopped = true;
		pthread_mutex_unlock(&data->lock_stop);
		return (true);
	}
	return (false);
}

void	monitor(t_data *data)
{
	int		i;

	while (true)
	{
		if (check_meals(data))
		{
			pthread_mutex_lock(&data->lock_stop);
			data->simulation_stopped = true;
			pthread_mutex_unlock(&data->lock_stop);
			return ;
		}
		i = 0;
		while (i < data->nbr_philo)
		{
			if (check_death(data, i))
				return ;
			i++;
		}
		usleep(1000);
	}
}

bool	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (false);
		i++;
	}
	pthread_mutex_lock(&data->lock_ready);
	data->all_threads_ready = true;
	pthread_mutex_unlock(&data->lock_ready);
	monitor(data);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (false);
	}
	return (true);
}
