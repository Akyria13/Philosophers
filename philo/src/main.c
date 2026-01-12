/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/12 18:20:09 by jowagner         ###   ########.fr       */
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

static void	only_one_philo(t_data *data)
{
	if (data->nbr_philo == 1)
	{
		pthread_mutex_lock(&data->philo->fork_left->mutex);
		print_activities(LEFT_FORK, data->philo);
		pthread_mutex_unlock(&data->philo->fork_left->mutex);
		while (is_sim_running(data))
			usleep(1000);
		return ;
	}
}

static bool	run_simulation(t_philo *philo)
{
	while (is_sim_running(philo->data))
	{
		if (!is_eating(philo))
			return (false);
		if (!is_sleeping(philo))
			return (false);
		if (!is_thinking(philo))
			return (false);
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (true)
	{
		pthread_mutex_lock(&philo->data->lock_ready);
		if (philo->data->all_threads_ready)
		{
			pthread_mutex_unlock(&philo->data->lock_ready);
			break ;
		}
		pthread_mutex_unlock(&philo->data->lock_ready);
		usleep(100);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	if (philo->data->nbr_philo == 1)
		only_one_philo(philo->data);
	run_simulation(philo);
	return (NULL);
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
