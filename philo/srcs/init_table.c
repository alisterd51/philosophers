/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:06:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 07:08:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "struct.h"

static t_arg	init_arg(int ac, char **av)
{
	t_arg	arg;

	arg.number_of_philosophers = (long long int)ft_atoi(av[0]);
	arg.time_to_die = (long long int)ft_atoi(av[1]) * 1000;
	arg.time_to_eat = (long long int)ft_atoi(av[2]) * 1000;
	arg.time_to_sleep = (long long int)ft_atoi(av[3]) * 1000;
	if (ac == 5)
		arg.number_of_eat = (long long int)ft_atoi(av[4]);
	else
		arg.number_of_eat = -1;
	return (arg);
}

int	init_table(t_table *table, int ac, char **av)
{
	int	num_philo;

	memset(table, 0, sizeof(t_table));
	if (ac == 4 || ac == 5)
		table->arg = init_arg(ac, av);
	else
		return (1);
	pthread_mutex_init(&table->m_life, NULL);
	pthread_mutex_init(&table->speak, NULL);
	table->life = 1;
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->arg.number_of_philosophers);
	if (table->fork == NULL)
		return (1);
	num_philo = 0;
	while (num_philo < table->arg.number_of_philosophers)
	{
		pthread_mutex_init(table->fork + num_philo, NULL);
		num_philo++;
	}
	return (0);
}
