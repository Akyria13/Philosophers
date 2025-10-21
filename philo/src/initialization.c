/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/10/21 18:10:39 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_die, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_eat, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->lock_print, NULL) != 0)
		return (false);
	return (true);
}

bool	init_data(t_data *data, int ac, char **av)
{
	data->start_time = 0;
	data->nbr_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_meal = ft_atoi(av[5]);
	else
		data->nbr_meal = -1;
	if (!init_mutex(data))
		return (false);
	// printf("Nbr philo = %d\nTime to die = %d\nTime to eat = %d\n"
	// 	"Time to sleep = %d\nNbr meal = %d\n",
	// 	data->nbr_philo, data->time_to_die, data->time_to_eat,
		// data->time_to_sleep, data->nbr_meal); //Debug
	// printf("Adresse de nbr_philo dans init_data =  %p\n", &data->nbr_philo); //Debug
	return (true);
}

bool	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].is_alive = true;
		philo[i].is_eating = false;
		philo[i].is_thinking = false;
		if (pthread_mutex_init(&philo[i].mutex, NULL) != 0)
			return (false);
		// printf("ID de philo dans init_philo = %d\n", philo[i].id); //Debug
	}
	// printf("Vérification de philo mort (1 = vivant, 0 = mort) = %d\n", philo->is_alive); //Debug
	return (true);
}

bool	init_fork(t_data *data, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		fork[i].id = i;
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
			return (false);
		// printf("ID de fork dans init_fork = %d\n", fork[i].id); //Debug
		i++;
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	long	current_time;

	philo = arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->lock_print);
		current_time = ft_time(philo->data);
		printf("%ld Philo id = %d\n", current_time, philo->id); //Debug
		pthread_mutex_unlock(&philo->data->lock_print);
		sleep(1);
	}
}

bool	init_thread(t_data *data, t_philo *philo)
{
	int			i;

	i = 0;
	// printf("Adresse de nbr_philo dans init_thread =  %p\n", &data->nbr_philo); //Debug
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		// printf("Valeur de i dans la boucle thread = %d\n", i); //Debug
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (false);
		i++;
	}
	// printf("nbr_philo après la boucle thread =  %d, i = %d\n", data->nbr_philo, i); //Debug
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (false);
	}
	return (true);
}
