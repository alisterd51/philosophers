/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 05:22:24 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 05:26:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "struct.h"

void	take_fork(t_philo *philo)
{
	const int	num = philo->num;

	if (num % 2)
	{
		pthread_mutex_lock(&philo->table->fork[num]);
		pthread_mutex_lock(&philo->table->fork[(num + 1)
			% philo->arg.number_of_philosophers]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->fork[(num + 1)
			% philo->arg.number_of_philosophers]);
		pthread_mutex_lock(&philo->table->fork[num]);
	}
}

void	drop_fork(t_philo *philo)
{
	const int	num = philo->num;

	if (num % 2)
	{
		pthread_mutex_unlock(philo->table->fork + ((num + 1)
				% philo->arg.number_of_philosophers));
		pthread_mutex_unlock(philo->table->fork + num);
	}
	else
	{
		pthread_mutex_unlock(philo->table->fork + num);
		pthread_mutex_unlock(philo->table->fork + ((num + 1)
				% philo->arg.number_of_philosophers));
	}
}
