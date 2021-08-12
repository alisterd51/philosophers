/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:42:01 by user42            #+#    #+#             */
/*   Updated: 2021/08/05 21:27:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_arg	t_arg;
struct	s_arg
{
	long long int	number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	number_of_eat;
};

typedef struct s_table	t_table;
struct	s_table
{
	t_timeval		begin;
	pthread_mutex_t	m_life;
	pthread_mutex_t	speak;
	pthread_mutex_t	*fork;
	t_arg			arg;
	int				life;
};

typedef struct s_philo	t_philo;
struct	s_philo
{
	t_table			*table;
	pthread_t		thread;
	t_timeval		begin;
	t_timeval		begin_eat;
	t_timeval		begin_sleep;
	t_timeval		current_time;
	t_arg			arg;
	int				num;
};

#endif
