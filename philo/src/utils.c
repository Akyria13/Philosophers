/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:34:27 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/05 15:11:33 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

long	ft_time(t_data *data)
{
	struct timeval tv;
	
	if (data->start_time == 0)
	{
		gettimeofday(&tv, NULL);
		// gettimeofday(&data->tv, NULL);
		data->start_time = (data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000);
	}
	gettimeofday(&tv, NULL);
	// gettimeofday(&data->tv, NULL);
	return ((data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000) - data->start_time);
}

bool	ft_sleep(t_data *data, int duration)
{
	long	start;
	long	elapsed;
	int		sleep_time;

	start = ft_time(data);
	elapsed = 0;
	while (elapsed < duration)
	{
		//Checker si le philo meurt pendant le temps écoulé.
		elapsed = ft_time(data) - start;
		if (duration - elapsed > 10)
			sleep_time = 10;
		else
			sleep_time = 1;
		sleep_time = sleep_time * 1000;
		usleep(sleep_time);
	}
	return (true);
}
