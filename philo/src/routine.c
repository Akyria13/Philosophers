/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:24:36 by jowagner          #+#    #+#             */
/*   Updated: 2025/10/22 18:05:18 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// bool	ft_routine(t_data *data)
// {
// 	/*
// 	tant que is_alive = true alors routine >
// 	*/
// }

void	print_activities(int status, t_philo *philo)
{
	long	current_time;

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

bool	is_alive(t_data *data)
{
	long	current_time;

	current_time = ft_time(data);
	if (current_time - data->philo->last_meal > data->time_to_die)
	{
		data->philo->is_alive = false;
		return (false);
	}
	// data->philo->time_since_last_meal = current_time - data->philo->last_meal;
	// if (data->philo->time_since_last_meal > data->time_to_die)
	// {
	// 	data->philo->is_alive = false;
	// 	return (false);
	// }
	return (true);
	/*
	si le temps écoulé est > à time_to_die alors is_alive = false;
	current_time - last_meal = time_since_last_meal
	si time_since_last_meal est > à TTD alors is_alive = false;
	*/
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

bool	is_eating(t_philo *philo)
{
	take_fork(philo);
	print_activities(EATING, philo);
	pthread_mutex_unlock(&philo->fork_left->mutex);
	pthread_mutex_unlock(&philo->fork_right->mutex);
// 	//	lock les fourchettes (surement avant)
// 	// pthread_mutex_lock(&philo->mutex);
// 	/*
// 	is_alive (???)
// 	lock
// 	printf (philo x "is eating")
// 	unlock
// 	mettre à jour last_meal
// 	tu manges le temps de TTE
// 	unlock les forks
// 	*/
// 	// pthread_mutex_unlock(&philo->mutex);
	// return (0);
	return (true);
}

// bool	is_sleeping(t_philo *philo)
// {
// 	/*
// 	is_alive (???)
// 	lock
// 	printf (philo x "is sleeping");
// 	unlock
// 	tu dodo le temps de TTS
// 	*/
// }

// bool	is_thinking(t_philo *philo)
// {
// 	/*
// 	is_alive (???)
// 	lock
// 	printf(philo x "is thinking");
// 	unlock
// 	*/
// }
