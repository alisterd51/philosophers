/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:56:14 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 07:00:47 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "struct.h"

static void	init_philo_table(t_table *table, t_philo *philo)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < table->arg.number_of_philosophers)
	{
		philo[num_philo].num = num_philo;
		philo[num_philo].table = table;
		philo[num_philo].arg = table->arg;
		num_philo++;
	}
}

static void	init_philo_time(t_table *table, t_philo *philo)
{
	int	num_philo;

	gettimeofday(&table->begin, NULL);
	num_philo = 0;
	while (num_philo < table->arg.number_of_philosophers)
	{
		philo[num_philo].begin = table->begin;
		philo[num_philo].begin_eat = table->begin;
		num_philo++;
	}
}

static void	init_philo_thread(int number_of_philosophers, t_philo *philo)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < number_of_philosophers)
	{
		pthread_create(&(philo[num_philo].thread), NULL,
			philosophize, philo + num_philo);
		num_philo++;
	}
}

t_philo	*init_philo(t_table *table)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo)
			* table->arg.number_of_philosophers);
	if (ret == NULL)
		return (NULL);
	memset(ret, 0, sizeof(t_philo) * table->arg.number_of_philosophers);
	init_philo_table(table, ret);
	init_philo_time(table, ret);
	init_philo_thread(table->arg.number_of_philosophers, ret);
	return (ret);
}
