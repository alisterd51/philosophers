/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:11:14 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 06:18:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"

int	begin_eat(t_philo *philo)
{
	take_fork(philo);
	secure_print("has taken a fork", philo);
	gettimeofday(&philo->begin_eat, NULL);
	secure_print("is eating", philo);
	return (2);
}

int	end_eat(t_philo *philo)
{
	drop_fork(philo);
	if (philo->arg.number_of_eat != -1)
		philo->arg.number_of_eat--;
	return (3);
}

int	begin_sleep(t_philo *philo)
{
	gettimeofday(&philo->begin_sleep, NULL);
	secure_print("is sleeping", philo);
	return (4);
}

int	end_sleep(t_philo *philo)
{
	secure_print("is thinking", philo);
	return (1);
}

int	death(t_philo *philo, int life)
{
	secure_print("died", philo);
	secure_death(philo->table);
	if (life == 2)
		drop_fork(philo);
	return (0);
}
