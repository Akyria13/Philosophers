/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:07:46 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/08 16:40:41 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define PHILO_MAX 200

typedef	struct	s_data t_data;

enum	e_status
{
	LEFT_FORK,
	RIGHT_FORK,
	DEAD,
	EATING,
	SLEEPING,
	THINKING
};

typedef struct s_fork
{
	int				id;
	// bool			available;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	t_fork			*fork_left;
	t_fork			*fork_right;
	t_data			*data;

	int				id;
	int				last_meal;
	int				meals_eaten;

	pthread_t		thread;
	pthread_mutex_t	mutex;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;

	t_fork			*fork;

	struct timeval tv;

	long			start_time;

	int				nbr_philo;
	int				nbr_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;

	bool			all_threads_ready;	bool			simulation_stopped;

	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_time;
	pthread_mutex_t	lock_ready;
	pthread_mutex_t	lock_stop;
}				t_data;

#endif
