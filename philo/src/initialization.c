/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/26 16:12:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_id(void *arg)
{
	t_philo 	*philo;

	philo = arg;
	while (1)
	{
		printf("Philo id =  %d\n", philo->id);
		sleep(1);
	}
}

void	init_thread(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i;
		pthread_create(&data->philo->thread, NULL, &print_id, "1"/*&data->philo->id[i]*/);
		i++;
	}
}

bool	init_struct(t_data *data, int ac, char **av)
{
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
	// if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
	// 	return (false);
	if (data)
		free(data);
	return (true);
}
