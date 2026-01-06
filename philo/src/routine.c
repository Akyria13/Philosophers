/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:24:36 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/06 16:17:17 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_sim_running(t_data *data)
{
	bool	running;

	pthread_mutex_lock(&data->lock_stop);
    running = !data->simulation_stopped;
    pthread_mutex_unlock(&data->lock_stop);
	return (running);
}

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->fork_left->mutex);
		print_activities(LEFT_FORK, philo);
		pthread_mutex_lock(&philo->fork_right->mutex);
		print_activities(RIGHT_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->fork_right->mutex);
		print_activities(RIGHT_FORK, philo);
		pthread_mutex_lock(&philo->fork_left->mutex);
		print_activities(LEFT_FORK, philo);
	}
}

void	print_activities(int status, t_philo *philo)
{
	long	current_time;
	bool	should_print;

	pthread_mutex_lock(&philo->data->lock_stop);
    should_print = !philo->data->simulation_stopped;
    pthread_mutex_unlock(&philo->data->lock_stop);
    if (!should_print && status != DEAD)
        return ;
		pthread_mutex_lock(&philo->data->lock_print);
	current_time = ft_time(philo->data);
	// if (status == LEFT_FORK || status == RIGHT_FORK)
	// 	printf("%ld %d has taken a fork\n", current_time, philo->id);
	if (status == LEFT_FORK)
		printf("%ld %d has taken a LEFT fork\n", current_time, philo->id);
	else if (status == RIGHT_FORK)
		printf("%ld %d has taken a RIGHT fork\n", current_time, philo->id);
	else if (status == EATING)
		printf("%ld %d is eating\n", current_time, philo->id);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", current_time, philo->id);
	else if (status == THINKING)
		printf("%ld %d is thinking\n", current_time, philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->lock_print);
}

bool	is_thinking(t_philo *philo)
{
	if (!is_sim_running(philo->data))
		return (false);
	print_activities(THINKING, philo);
	return (true);
}

bool	is_sleeping(t_philo *philo)
{
	if (!is_sim_running(philo->data))
		return (false);
	print_activities(SLEEPING, philo);
	ft_sleep(philo->data, philo->data->time_to_sleep);
	return (true);
}

bool	is_eating(t_philo *philo)
{
	if (!is_sim_running(philo->data))
		return (false);
	take_fork(philo);
	print_activities(EATING, philo);
	pthread_mutex_lock(&philo->mutex);
    philo->last_meal = ft_time(philo->data);
    pthread_mutex_unlock(&philo->mutex);
	// printf("Last meal de philo AVANT update %d : %d\n", philo->id, philo->last_meal);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal = ft_time(philo->data);
	pthread_mutex_unlock(&philo->mutex);
	// printf("Last meal de philo APRES update %d : %d\n", philo->id, philo->last_meal);
	ft_sleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork_left->mutex);
	pthread_mutex_unlock(&philo->fork_right->mutex);
	return (true);
}
