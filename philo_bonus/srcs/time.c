/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:35:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/08/06 08:57:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"
#include "struct.h"

long int	time_passed_since(t_timeval *begin_time, t_timeval *current_time)
{
	gettimeofday(current_time, NULL);
	return ((current_time->tv_sec * 1000000 + current_time->tv_usec)
		- (begin_time->tv_sec * 1000000 + begin_time->tv_usec));
}

int	check_time_to_eat(t_philo *philo)
{
	return (time_passed_since(&philo->begin_eat, &philo->current_time)
		>= philo->arg.time_to_eat);
}

int	check_time_to_sleep(t_philo *philo)
{
	return (time_passed_since(&philo->begin_sleep, &philo->current_time)
		>= philo->arg.time_to_sleep);
}

int	check_to_eat(t_philo *philo)
{
	if (philo->num)
		return (1);
	else if (philo->arg.number_of_philosophers % 2)
	{
		if (philo->arg.time_to_eat == philo->arg.time_to_sleep)
			return (philo->arg.time_to_die > (philo->arg.time_to_eat * 3));
		else if (philo->arg.time_to_sleep > philo->arg.time_to_eat)
			return (philo->arg.time_to_die
				> philo->arg.time_to_sleep + philo->arg.time_to_eat);
		else
			return (philo->arg.time_to_die > (philo->arg.time_to_eat * 4));
	}
	else
		return (philo->arg.time_to_die >= philo->arg.time_to_eat * 2
			&& philo->arg.time_to_die >= philo->arg.time_to_sleep * 2);
}

int	check_to_death(t_philo *philo)
{
	return (time_passed_since(&philo->begin_eat, &philo->current_time)
		>= philo->arg.time_to_die);
}
