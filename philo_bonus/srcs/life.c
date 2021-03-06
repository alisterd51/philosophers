/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:35:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/08/06 06:31:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <semaphore.h>
#include <unistd.h>
#include "philo.h"
#include "struct.h"

int	life(int num_philo, t_philo *philo)
{
	int	life;

	philo->num = num_philo;
	life = 1 + (2 * (philo->num % 2));
	sem_wait(philo->table->m_life);
	gettimeofday(&philo->begin, NULL);
	gettimeofday(&philo->begin_eat, NULL);
	while (life)
	{
		if (philo->arg.number_of_eat == 0)
			life = 0;
		if (life == 1 && check_to_eat(philo))
			life = begin_eat(philo);
		else if (life == 2 && check_time_to_eat(philo))
			life = end_eat(philo);
		else if (life == 3)
			life = begin_sleep(philo);
		else if (life == 4 && check_time_to_sleep(philo))
			life = end_sleep(philo);
		if (check_to_death(philo))
			life = death(philo, life);
		usleep(100);
	}
	sem_post(philo->table->m_life);
	return (0);
}
