/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlarma <anlarma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:48:41 by anlarma           #+#    #+#             */
/*   Updated: 2021/08/06 09:13:00 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <semaphore.h>
#include "philo.h"
#include "struct.h"

static void	free_all(t_table *table)
{
	sem_close(table->fork);
	sem_close(table->m_life);
	sem_close(table->speak);
}

static int	check_param(int	ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (1);
	if (!secure_atoi(av[0]) || !secure_atoi(av[1])
		|| !secure_atoi(av[2]) || !secure_atoi(av[3])
		|| (ac == 5 && !secure_atoi(av[4])))
		return (1);
	if (ft_atoi(av[0]) < 0 || ft_atoi(av[1]) < 0
		|| ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| (ac == 5 && ft_atoi(av[4]) < 0))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	philo;

	if (check_param(ac - 1, av + 1) || init_table(&table, ac - 1, av + 1))
		return (1);
	if (init_philo(&philo, &table))
	{
		free_all(&table);
		return (1);
	}
	if (init_fork(&philo, &table))
		return (0);
	start_life(&table);
	usleep(1000);
	end_life(&table);
	free_all(&table);
	return (0);
}
