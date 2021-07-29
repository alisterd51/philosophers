/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 05:36:22 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/28 06:32:35 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "struct.h"

static int	check_time_to_eat(t_philo *philo)
{
	return (time_passed_since(&philo->begin_eat, &philo->current_time)
		>= philo->arg.time_to_eat);
}

static int	check_time_to_sleep(t_philo *philo)
{
	return (time_passed_since(&philo->begin_sleep, &philo->current_time)
		>= philo->arg.time_to_sleep);
}

void	*philosophize(void *arg)
{
	t_philo	*philo;
	int		life;

	philo = (t_philo *)arg;
	life = 1 + (2 * (philo->num % 2));
	while (life)
	{
		if (philo->arg.number_of_eat == 0)
			life = 0;
		if (life == 1 && philo->arg.number_of_philosophers > 1)
			life = begin_eat(philo);
		else if (life == 2 && check_time_to_eat(philo))
			life = end_eat(philo);
		else if (life == 3)
			life = begin_sleep(philo);
		else if (life == 4 && check_time_to_sleep(philo))
			life = end_sleep(philo);
		if (!secure_check_life(philo->table)
			|| (time_passed_since(&philo->begin_eat, &philo->current_time)
				>= philo->arg.time_to_die))
			life = death(philo, life);
		usleep(100);
	}
	return (NULL);
}
