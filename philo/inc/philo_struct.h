/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:07:46 by jowagner          #+#    #+#             */
/*   Updated: 2025/10/21 16:48:26 by jowagner         ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo
{
	t_fork			*fork_left;
	t_fork			*fork_right;
	t_data			*data;

	int				id;
	int				last_meal;

	bool			is_alive;
	bool			is_eating;
	bool			is_thinking;

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

	pthread_mutex_t	lock_meal;
	pthread_mutex_t	lock_die;
	pthread_mutex_t	lock_eat;
	pthread_mutex_t	lock_print;
}				t_data;

#endif