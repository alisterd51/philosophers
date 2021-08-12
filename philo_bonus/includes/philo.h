/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:03:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/08/06 07:38:27 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

/*
** init.c
*/
t_arg		init_arg(int ac, char **av);
int			init_table(t_table *table, int ac, char **av);
int			init_philo(t_philo *philo, t_table *table);
int			init_fork(t_philo *philo, t_table *table);

/*
** life.c
*/
int			life(int num_philo, t_philo *philo);
void		start_life(t_table *table);
void		end_life(t_table *table);

/*
** life_tools1.c
*/
int			begin_eat(t_philo *philo);
int			end_eat(t_philo *philo);
int			begin_sleep(t_philo *philo);
int			end_sleep(t_philo *philo);
int			death(t_philo *philo, int life);

/*
** life_tools2.c
*/
void		take_fork(t_philo *philo);
void		drop_fork(t_philo *philo);
void		secure_print(const char *str, t_philo *philo);
void		start_life(t_table *table);
void		end_life(t_table *table);

/*
** time.c
*/
long int	time_passed_since(t_timeval *begin_time, t_timeval *current_time);
int			check_time_to_eat(t_philo *philo);
int			check_time_to_sleep(t_philo *philo);
int			check_to_eat(t_philo *philo);
int			check_to_death(t_philo *philo);

/*
** ft.c
*/
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

/*
** secure_atoi.c
*/
int			secure_atoi(const char *str);

#endif
