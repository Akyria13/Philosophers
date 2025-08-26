/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/26 17:55:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	// int		i;
	
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
	data = init_data(ac, av);
	if (!data)
		return (1);
	init_thread(data, &data->philo);
	free(data);
	// i = 0;
	// while (i < data->nbr_philo)
	// {
    //     data->philo[i].id = i + 1;
	// 	pthread_join(data->philo->thread, NULL);
	// 	i++;
	// }
	return (0);
}

/*TODO*/
/*memset philo
* ou pas sur philo
condition if dans create & join*/

/*prompt à Claude pedagogue + les sources*/