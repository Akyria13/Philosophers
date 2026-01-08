/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/08 16:14:30 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	meals_count(t_data *data)
{
	int	i;
	int	philo_full;

	while (true)
	{
		if (data->nbr_meal > 0)
		{
			i = 0;
			philo_full = 0;
			while (i < data->nbr_philo)
			{
				pthread_mutex_lock(&data->philo[i].mutex);
				if (data->philo[i].meals_eaten >= data->nbr_meal)
					philo_full++;
				pthread_mutex_unlock(&data->philo[i].mutex);
				i++;
			}
			if (philo_full == data->nbr_philo)
			{
				pthread_mutex_lock(&data->lock_stop);
				data->simulation_stopped = true;
				pthread_mutex_unlock(&data->lock_stop);
				return ;
			}
		}
	}
	return ;
}

/*
Probleme du programme qui s arrete pas quand tous les philos sont full

Ajouter un tableau de booleen. False si le philo n'est pas full | True si le philo est full
Checker chaque case du tableau -> Si tous TRUE -> all_full = true
Si all_full = true -> arreter le programme

*/

void	monitor(t_data *data)
{
	long	current_time;
	long	last_meal;
	int		i;

	if (data->nbr_meal > 0)
		meals_count(data);
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
				return ;
			}
			if (data->nbr_meal == 0)
				return ;
			i++;
		}
		usleep(1000);
	}
	return ;
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
