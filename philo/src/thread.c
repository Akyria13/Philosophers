/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/27 17:33:32 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_id(void *arg)
{
	t_philo 	*philo;

	philo = arg;
	while (1)
	{
    	pthread_mutex_lock(&philo->mutex);
		printf("Philo id =  %d\n", philo->id);
		// printf("Philo is_alive =  %d\n", philo->is_alive);
		// printf("---\n");
    	pthread_mutex_unlock(&philo->mutex);
		sleep(1);
	}
}

int	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	printf("Philo nbr init thread =  %p\n", &data->nbr_philo);
	while (i < data->nbr_philo)
	{
        printf("Philo nbr dans thread =  %d i = %d\n", data->nbr_philo, i);
		philo[i].id = i + 1;
		printf("Valeur de i : %d\n", i);
		pthread_mutex_init(&philo[i].mutex, NULL);
		if (pthread_create(&philo[i].thread, NULL, &print_id, &philo[i]))
            return (1);
		i++;
	}
    i = 0;
	while (i < data->nbr_philo)
        pthread_join(philo[i++].thread, NULL);
        
	return (0);
}
