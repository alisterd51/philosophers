/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:25:59 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 05:11:35 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "philo.h"

int	secure_check_life(t_table *table)
{
	int	ret;

	pthread_mutex_lock(&table->m_life);
	ret = table->life;
	pthread_mutex_unlock(&table->m_life);
	return (ret);
}

void	secure_nolife(t_table *table)
{
	pthread_mutex_lock(&table->m_life);
	table->life = -1;
	pthread_mutex_unlock(&table->m_life);
}

void	secure_death(t_table *table)
{
	pthread_mutex_lock(&table->m_life);
	table->life = 0;
	pthread_mutex_unlock(&table->m_life);
}

void	secure_life(t_table *table)
{
	pthread_mutex_lock(&table->m_life);
	table->life = 1;
	pthread_mutex_unlock(&table->m_life);
}

void	secure_print(const char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->speak);
	if (secure_check_life(philo->table))
		printf("%ld %d %s\n", time_passed_since(&philo->begin,
				&philo->current_time) / 1000, philo->num, str);
	pthread_mutex_unlock(&philo->table->speak);
}
