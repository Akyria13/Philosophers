/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:19:04 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/21 18:10:58 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cacaprout(void *arg)
{
	printf("salut je suis %s\n", (char *)arg);
	return (NULL);
}

void	init_thread(t_philo *philo)
{
	// t_philo *philo;
	// int		i;

	// philo = data->philo;
	// i = 0;
	// while (i < data->nbr_philo)
	// printf("error");
	if (pthread_create(&philo->thread, NULL, cacaprout, "1") != 0)
	{
		printf("error");
		exit(1);
	}
	// if (pthread_join(philo->thread, NULL) != 0)
	// {
	// 	perror("error");
	// 	exit(1);
	// }
	printf("init thread fini");
}

bool	init_struct(t_data *data, char **av)
{
	data = calloc(1, sizeof(t_data));
	if (!data)
		return (false);
	data->nbr_philo = ft_atoi(av[1]);
	if (pthread_mutex_init(&data->lock_meal, NULL) != 0)
		return (false);
	return (true);
}
