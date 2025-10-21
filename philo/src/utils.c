/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:34:27 by jowagner          #+#    #+#             */
/*   Updated: 2025/10/20 18:43:57 by jowagner         ###   ########.fr       */
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
	// printf("%ld\n", ((data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000)) - data->start_time);
	return ((data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000) - data->start_time);
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
