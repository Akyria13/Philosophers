/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/09/03 16:30:17 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_data(t_data *data, int ac, char **av)
{
	printf("<<< INIT_DATA >>>\n"); //Debug
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_meal = ft_atoi(av[5]);
	else
		data->nbr_meal = -1;
	/*Faire une fonction get_time pour commencer le chrono ?*/ //Debug
	/*Initialiser les mutex de ma structure data ici ?*/ //Debug
	printf("Nbr philo = %d\nTime to die = %d\nTime to eat = %d\n"
		"Time to sleep = %d\nNbr meal = %d\n",
		data->nbr_philo, data->time_to_die, data->time_to_eat,
		data->time_to_sleep, data->nbr_meal); //Debug
	printf("Adresse de nbr_philo dans init_data =  %p\n", &data->nbr_philo); //Debug
	printf("---\n"); //Debug
	return (true);
}

bool	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	printf("<<< INIT_PHILO >>>\n"); //Debug
	while (++i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_alive = true;
		philo[i].is_eating = false;
		philo[i].is_thinking = false;
		printf("ID de philo dans init_philo = %d\n", philo[i].id);
	}
	printf("Vérification de philo mort (1 = vivant, 0 = mort) = %d\n", philo->is_alive);
	printf("---\n"); //Debug
	return (true);
}

bool	init_fork(t_data *data, t_fork *fork)
{
	(void)data;
	(void)fork;
	printf("<<< INIT_FORK >>>\n"); //Debug
	printf("Test fork\n"); //Debuf
	printf("---\n"); //Debug
	return (true);
}

void	*print_id(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		printf("Philo id =  %d\n", philo->id);
		// printf("Philo is_alive =  %d\n", philo->is_alive); //Debug
		// printf("---\n"); //Debug
		pthread_mutex_unlock(&philo->mutex);
		sleep(1);
	}
}

bool	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	printf("<<< INIT_THREAD >>>\n"); //Debug
	printf("Adresse de nbr_philo dans init_thread =  %p\n", &data->nbr_philo);
	while (i <= data->nbr_philo)
	{
		printf("nbr_philo dans la boucle thread =  %d, i = %d\n", data->nbr_philo, i);
		philo[i].id = i + 1;
		printf("Valeur de i dans la boucle thread = %d\n", i);
		pthread_mutex_init(&philo[i].mutex, NULL);
		if (pthread_create(&philo[i].thread, NULL, &print_id, &philo[i]))
			return (false);
		i++;
	}
	i = 0;
	while (i <= data->nbr_philo)
		pthread_join(philo[i++].thread, NULL);
	return (true);
}
