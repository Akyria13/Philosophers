/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolanwagner13 <jolanwagner13@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:18:48 by jowagner          #+#    #+#             */
/*   Updated: 2025/12/22 19:19:17 by jolanwagner      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		is_eating(philo);
		sleep(1);
	}
}

bool	init_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (false);
		i++;
	}
	//Lance la boucle de monitoring (check s'il faut metre fin à la simulation).
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(philo[i++].thread, NULL) != 0)
			return (false);
	}
	return (true);
}
