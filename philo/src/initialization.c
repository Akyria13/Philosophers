/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/26 17:54:44 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_id(void *arg)
{
	t_philo 	*philo;

	philo = arg;
	// printf("Philo id avant lock =  %d\n", philo->id);
    pthread_mutex_lock(&philo->mutex);
	printf("Philo id =  %d\n", philo->id);
	printf("Philo is_alive =  %d\n", philo->is_alive);
    pthread_mutex_unlock(&philo->mutex);
	sleep(1);
	return NULL;
}

void	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	pthread_mutex_init(&philo->mutex, NULL);
	while (i <= data->nbr_philo)
	{
		philo[i].id = i;
		if (pthread_create(&philo[i].thread, NULL, &print_id, &philo[i]))
			exit (1);
		i++;
	}
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (false);
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_meal = ft_atoi(av[5]);
	printf("Nbr philo = %d\nTime to die = %d\nTime to eat = %d\nTime to sleep = %d\nNbr meal = %d\n", data->nbr_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->nbr_meal);
	return (data);
}
