/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:35:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/29 19:49:58 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#include <stdio.h>
#include <unistd.h>

int	life(int num_philo, t_philo *philo)
{
	printf("Je suis philo%d\n", num_philo);
	(void)philo;
	return (0);
}

void	end_life(t_table *table)
{
	(void)table;
}
