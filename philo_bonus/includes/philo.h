/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 02:03:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/29 19:57:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"

/*
**
*/
int		init_table(t_table *table, int ac, char **av);
int		init_philo(t_philo *philo, t_table *table);
void	free_all(t_philo *philo, t_table *table);

/*
** life.c
*/
int		life(int num_philo, t_philo *philo);
void	end_life(t_table *table);

/*
** ft.c
*/
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

/*
** secure_atoi.c
*/
int		secure_atoi(const char *str);

#endif
