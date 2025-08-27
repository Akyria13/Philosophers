/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/27 16:19:14 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_id(void *arg)
{
	t_philo 	*philo;

	philo = arg;
	while (1)
	{
		printf("Philo id avant lock =  %d\n", philo->id);
    	pthread_mutex_lock(&philo->mutex);
		printf("Philo id =  %d\n", philo->id);
		printf("Philo is_alive =  %d\n", philo->is_alive);
		printf("---\n");
    	pthread_mutex_unlock(&philo->mutex);
		sleep(1);
	}
}

int	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	while (i <= data->nbr_philo)
	{
		philo[i].id = i;
		pthread_mutex_init(&philo[i].mutex, NULL);
		if (pthread_create(&philo[i].thread, NULL, &print_id, &philo[i]))
			exit (1);
		i++;
	}
	return (0);
}
