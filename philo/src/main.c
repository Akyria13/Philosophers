/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/24 18:08:55 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

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
	data = NULL;
	if (!init_struct(data, av))
		return (1);
	init_thread(data);
	i = 0;
	while (i < data->nbr_philo)
	{
        data->philo[i].id = i + 1;
		pthread_join(data->philo->thread[i], NULL);
		i++;
	}
	return (0);
}
