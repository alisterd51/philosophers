/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlarma <anlarma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:48:41 by anlarma           #+#    #+#             */
/*   Updated: 2021/07/29 19:58:47 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "philo.h"

#include <stdio.h>

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
	return (0);
}

int	init_philo(t_philo *philo, t_table *table)
{
	(void)philo;
	(void)table;
	return (0);
}

void	free_all(t_philo *philo, t_table *table)
{
	(void)philo;
	(void)table;
}

int	check_param(int	ac, char **av)
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
	int		num_philo;
	pid_t	id;

	if (check_param(ac - 1, av + 1) || init_table(&table, ac - 1, av + 1))
		return (1);
	if (init_philo(&philo, &table))
	{
		free_all(&philo, &table);
		return (1);
	}
	num_philo = 0;
	id = 1;
	while (id && num_philo < table.arg.number_of_philosophers)
	{
		id = fork();
		if (!id)
			return (life(num_philo, &philo));
		num_philo++;
	}
	end_life(&table);
	free_all(&philo, &table);
	return (0);
}
