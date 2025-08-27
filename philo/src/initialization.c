/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/27 16:19:40 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	init_philo(t_philo *philo)
// {
// 	philo = ft_calloc(1, sizeof(t_philo));
// 	if (!philo)
// 		return ;
// }

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
	else
		data->nbr_meal = -1;
	/*Faire une fonction get_time pour commencer le chrono ?*/
	/*Initialiser les mutex de ma structure data ici ?*/
	printf("Nbr philo = %d\nTime to die = %d\nTime to eat = %d\n"
		"Time to sleep = %d\nNbr meal = %d\n",
		data->nbr_philo, data->time_to_die, data->time_to_eat,
		data->time_to_sleep, data->nbr_meal); //Debug
	printf("---\n");
	return (data);
}

