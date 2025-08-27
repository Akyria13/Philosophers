/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/27 16:22:19 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_everything(t_data *data, int ac, char **av)
{
	data = init_data(ac, av);
	if (!data)
		return (false);
	if (!init_thread(data, &data->philo))
	{
		return (false);
	}
	return (true);
}

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
	data = NULL;
	if (!init_everything(data, ac, av))
		return (1);
	free(data);
	return (0);
}

/*
* TODO
* - Initialiser la structure philo.
* - Condition if dans create & join dans mes threads.
*/

/*prompt à Claude pedagogue + les sources*/