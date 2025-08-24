/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:20 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/24 17:30:33 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_struct.h"

//- Initialization -//
void    	init_thread(t_data *data);
bool	   	init_struct(t_data *data, char **av);
//--- --- --- --- ---//

/*Parsing*/
int			str_to_int(char *str);
bool		parsing(int ac, char **av);
//--- --- --- --- ---//

/*Utils*/
int			ft_atoi(char *str);
//--- --- --- --- ---//

#endif