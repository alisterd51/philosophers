/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:03:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/29 01:48:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

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

/*
** secure_atoi.c
*/
int			secure_check_life(t_table *table);
void		secure_nolife(t_table *table);
void		secure_death(t_table *table);
void		secure_life(t_table *table);
void		secure_print(const char *str, t_philo *philo);

/*
** use_fork.c
*/
void		take_fork(t_philo *philo);
void		drop_fork(t_philo *philo);

/*
** philosophize.c
*/
void		*philosophize(void *arg);

/*
** life.c
*/
int			begin_eat(t_philo *philo);
int			end_eat(t_philo *philo);
int			begin_sleep(t_philo *philo);
int			end_sleep(t_philo *philo);
int			death(t_philo *philo, int life);

/*
** init_philo.c
*/
t_philo		*init_philo(t_table *table);

/*
** init_table.c
*/
int			init_table(t_table *table, int ac, char **av);

/*
** philo.c
*/
long int	time_passed_since(t_timeval *begin_time, t_timeval *current_time);

#endif
