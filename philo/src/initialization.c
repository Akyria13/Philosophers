/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/31 18:40:06 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(t_data *data, int ac, char **av)
{
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
	printf("Philo nbr init dans init data =  %p\n", &data->nbr_philo);
	printf("---\n");
	return (data);
}

// void	init_philo(t_philo *philo)
// {
// }

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
