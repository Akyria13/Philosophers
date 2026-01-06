/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/06 14:48:36 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	//Lock des threads jusqu'à la création de tous les threads.
	while (is_sim_running(philo->data))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		sleep(1);
	}
	return (NULL);
}

static bool	init_everything(t_data *data, t_philo *philo, int ac, char **av)
{
	if (!init_data(data, ac, av)
		|| !init_philo(data, philo)
		|| !init_fork(data, data->fork)
		|| !init_thread(data, philo))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo[PHILO_MAX];
	t_fork	fork[PHILO_MAX];

	// data.start_time = 0;
	if (ac < 5 || ac > 6)
	{
		printf("The number of arguments must be :\n- Number of philosophers\n"
			"- Time to die\n- Time to eat\n- Time to sleep\n"
			"- (optionnal) Number of meals");
		return (1);
	}
	if (!parsing(ac, av))
	{
		printf("Arguments are incorrect.");
		return (1);
	}
	data.philo = philo;
	data.fork = fork;
	if (!init_everything(&data, philo, ac, av))
		return (1);
	return (0);
}
