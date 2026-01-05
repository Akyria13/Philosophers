/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:32:20 by jowagner          #+#    #+#             */
/*   Updated: 2026/01/05 14:30:55 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_struct.h"

//- Initialization -//
bool		init_data(t_data *data, int ac, char **av);
bool		init_philo(t_data *data, t_philo *philo);
bool		init_fork(t_data *data, t_fork *fork);
bool		init_thread(t_data *data, t_philo *philo);
//--- --- --- --- ---//

/*Parsing*/
bool		parsing(int ac, char **av);
//--- --- --- --- ---//

/*Routine*/
void		print_activities(int status, t_philo *philo);
// bool		is_alive(t_data *data);
void		take_fork(t_philo *philo);
bool		is_eating(t_philo *philo);
bool		is_thinking(t_philo *philo);
bool		is_sleeping(t_philo *philo);
//--- --- --- --- ---//

/*Thread*/
//--- --- --- --- ---//

/*Utils*/
int			ft_atoi(char *str);
long		ft_time(t_data *data);
bool		ft_sleep(t_data *data, int duration);
// void	    ft_bzero(void *s, size_t n);
// void	    *ft_memset(void *str, int c, size_t n);
// void	    *ft_calloc(size_t count, size_t size);
//--- --- --- --- ---//

#endif
