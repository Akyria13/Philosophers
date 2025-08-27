/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:20 by jowagner          #+#    #+#             */
/*   Updated: 2025/08/27 16:21:05 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_struct.h"

//- Initialization -//
t_data	    *init_data(int ac, char **av);
//--- --- --- --- ---//

/*Parsing*/
int			str_to_int(char *str);
bool		parsing(int ac, char **av);
//--- --- --- --- ---//

/*Thread*/
int    	    init_thread(t_data *data, t_philo *philo);
//--- --- --- --- ---//

/*Utils*/
int			ft_atoi(char *str);
void	    ft_bzero(void *s, size_t n);
void	    *ft_memset(void *str, int c, size_t n);
void	    *ft_calloc(size_t count, size_t size);
//--- --- --- --- ---//

#endif