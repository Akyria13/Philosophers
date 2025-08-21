/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/21 18:25:44 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_struct.h"

int	main(int ac, char **av)
{
	t_data	*data;

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
	if (!init_struct(data, av))
		return (1);
	init_thread(data->philo);
	return (0);
}
