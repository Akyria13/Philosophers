/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/05 15:26:49 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	//Lock des threads jusqu'à la création de tous les threads.
	while (1)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		sleep(1);
	}
}

void	init_monitor(t_data *data)
{
	long	current_time;
	int		i;

	i = 0;
	current_time = ft_time(data);
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->philo[i].mutex);
		if (current_time - data->philo[i].last_meal > data->time_to_die)
		{
			data->philo->is_alive = false;
			print_activities(DEAD, data->philo);
			return ;
		}
		pthread_mutex_unlock(&data->philo[i].mutex);
		i++;
	}
	// data->philo->time_since_last_meal = current_time - data->philo->last_meal;
	// if (data->philo->time_since_last_meal > data->time_to_die)
	// {
	// 	data->philo->is_alive = false;
	// 	return (false);
	// }
	/*
	Si le temps écoulé est > à time_to_die alors is_alive = false;
	current_time - last_meal = time_since_last_meal;
	Si time_since_last_meal est > à TTD alors is_alive = false;
	*/
	return ;
}

bool	init_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	// data->start_time = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (false);
		i++;
	}
	init_monitor(data); //Lance la boucle de monitoring (check s'il faut metre fin à la simulation).
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (false);
	}
	return (true);
}
