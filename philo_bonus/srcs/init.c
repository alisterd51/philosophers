/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlarma <anlarma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:48:41 by anlarma           #+#    #+#             */
/*   Updated: 2021/08/06 09:12:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "philo.h"
#include "struct.h"

t_arg	init_arg(int ac, char **av)
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
	table->arg = init_arg(ac, av);
	sem_unlink("fork");
	sem_unlink("speak");
	sem_unlink("m_life");
	table->m_life = sem_open("m_life", O_CREAT, S_IRWXU, 0);
	table->fork = sem_open("fork", O_CREAT, S_IRWXU,
			table->arg.number_of_philosophers);
	table->speak = sem_open("speak", O_CREAT, S_IRWXU, 1);
	return (0);
}

int	init_philo(t_philo *philo, t_table *table)
{
	philo->arg = table->arg;
	philo->table = table;
	return (0);
}

int	init_fork(t_philo *philo, t_table *table)
{
	int		num_philo;
	pid_t	id;

	num_philo = 0;
	id = 1;
	while (id && num_philo < table->arg.number_of_philosophers)
	{
		id = fork();
		if (!id)
		{
			life(num_philo, philo);
			return (1);
		}
		num_philo++;
	}
	return (0);
}
