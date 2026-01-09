/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:24:36 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/09 15:14:40 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (status == LEFT_FORK || status == RIGHT_FORK)
		printf("%ld %d has taken a fork\n", current_time, philo->id);
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
	if (philo->id % 2 == 0)
		usleep(1000);
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
	int	current_meals;

	if (!is_sim_running(philo->data))
		return (false);
	if (philo->data->nbr_meal > 0)
	{
		pthread_mutex_lock(&philo->mutex);
		current_meals = philo->meals_eaten;
		pthread_mutex_unlock(&philo->mutex);
		if (current_meals >= philo->data->nbr_meal)
			return (false);
	}
	take_fork(philo);
	print_activities(EATING, philo);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal = ft_time(philo->data);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex);
	ft_sleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork_left->mutex);
	pthread_mutex_unlock(&philo->fork_right->mutex);
	return (true);
}
