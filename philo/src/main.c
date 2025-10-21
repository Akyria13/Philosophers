/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/10/20 19:12:24 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
