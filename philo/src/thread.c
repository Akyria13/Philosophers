/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/06 16:19:56 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_data	*data;
	long	current_time;
	long	last_meal;
	int		i;

	data = (t_data *)arg;
	while (true)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
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
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

// void	*monitor(void *arg)
// {
// 	t_data	*data;
// 	long	current_time;
// 	long	last_meal;
// 	int		i;

// 	data = (t_data *)arg;
// 	i = 0;
// 	current_time = ft_time(data);
// 	while (i < data->nbr_philo)
// 	{
// 		pthread_mutex_lock(&data->philo[i].mutex);
// 		if (current_time - data->philo[i].last_meal > data->time_to_die)
// 		{
// 			data->philo->is_alive = false;
// 			print_activities(DEAD, data->philo);
// 			return (NULL);
// 		}
// 		else if (data->philo->is_alive == false)
// 		{
// 			pthread_mutex_lock(&data->lock_stop);
//     		data->simulation_stopped = true;
//     		pthread_mutex_unlock(&data->lock_stop);
// 		}
// 		pthread_mutex_unlock(&data->philo[i].mutex);
// 		usleep(1000);
// 		i++;
// 	}
// 	// data->philo->time_since_last_meal = current_time - data->philo->last_meal;
// 	// if (data->philo->time_since_last_meal > data->time_to_die)
// 	// {
// 	// 	data->philo->is_alive = false;
// 	// 	return (false);
// 	// }
// 	/*
// 	Si le temps écoulé est > à time_to_die alors is_alive = false;
// 	current_time - last_meal = time_since_last_meal;
// 	Si time_since_last_meal est > à TTD alors is_alive = false;
// 	*/
// 	return (NULL);
// }

bool	init_thread(t_data *data, t_philo *philo)
{
	pthread_t 	monitor_thread;
	int			i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (false);
		i++;
	}
	// pthread_mutex_lock(&data->lock_ready);
    // data->all_threads_ready = true;
    // pthread_mutex_unlock(&data->lock_ready);
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (false);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (false);
	}
	pthread_join(monitor_thread, NULL);
	return (true);
}
