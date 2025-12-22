/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolanwagner13 <jolanwagner13@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:34:27 by jowagner          #+#    #+#             */
/*   Updated: 2025/12/22 19:16:05 by jolanwagner      ###   ########.fr       */
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
	if (data->start_time == 0)
	{
		gettimeofday(&data->tv, NULL);
		data->start_time = (data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000);
	}
	gettimeofday(&data->tv, NULL);
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

// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, '\0', n);
// }

// void	*ft_memset(void *str, int c, size_t n)
// {
// 	char	*s;

// 	s = (char *)str;
// 	while (n > 0)
// 	{
// 		s[n - 1] = c;
// 		n--;
// 	}
// 	return (str);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*str;

// 	if (size != 0 && count > SIZE_MAX / size)
// 		return (NULL);
// 	str = malloc(count * size);
// 	if (!str)
// 		return (NULL);
// 	ft_bzero(str, count * size);
// 	return (str);
// }
