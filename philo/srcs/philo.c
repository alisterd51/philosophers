/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:10:41 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/29 01:49:24 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "struct.h"

long int	time_passed_since(t_timeval *begin_time, t_timeval *current_time)
{
	gettimeofday(current_time, NULL);
	return ((current_time->tv_sec * 1000000 + current_time->tv_usec)
		- (begin_time->tv_sec * 1000000 + begin_time->tv_usec));
}

static void	join_philo(t_table *table, t_philo *philo)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < table->arg.number_of_philosophers)
	{
		pthread_join(philo[num_philo].thread, NULL);
		num_philo++;
	}
}

static void	free_all(t_table *table, t_philo **philo)
{
	free(table->fork);
	table->fork = NULL;
	free(*philo);
	*philo = NULL;
}

static int	check_param(int	ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (1);
	if (!secure_atoi(av[0]) || !secure_atoi(av[1])
		|| !secure_atoi(av[2]) || !secure_atoi(av[3])
		|| (ac == 5 && !secure_atoi(av[4])))
		return (1);
	if (ft_atoi(av[0]) < 0 || ft_atoi(av[1]) < 0
		|| ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| (ac == 5 && ft_atoi(av[4]) < 0))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philo;

	if (check_param(ac - 1, av + 1) || init_table(&table, ac - 1, av + 1))
		return (1);
	philo = init_philo(&table);
	if (philo == NULL)
	{
		free_all(&table, &philo);
		return (1);
	}
	join_philo(&table, philo);
	free_all(&table, &philo);
	return (0);
}
