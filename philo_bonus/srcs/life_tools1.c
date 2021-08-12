/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_tools1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:35:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/08/06 09:29:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <signal.h>
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
	kill(0, SIGINT);
	if (life == 2)
		drop_fork(philo);
	return (0);
}
