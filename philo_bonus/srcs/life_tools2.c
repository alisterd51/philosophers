/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:35:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/08/11 23:53:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include "philo.h"
#include "struct.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->table->fork);
	sem_wait(philo->table->fork);
}

void	drop_fork(t_philo *philo)
{
	sem_post(philo->table->fork);
	sem_post(philo->table->fork);
}

void	secure_print(const char *str, t_philo *philo)
{
	sem_wait(philo->table->speak);
	printf("%ld %d %s\n", time_passed_since(&philo->begin,
			&philo->current_time) / 1000, philo->num + 1, str);
	sem_post(philo->table->speak);
}

void	start_life(t_table *table)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo++ < table->arg.number_of_philosophers)
		sem_post(table->m_life);
}

void	end_life(t_table *table)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo++ < table->arg.number_of_philosophers)
		sem_wait(table->m_life);
}
