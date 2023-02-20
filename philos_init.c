/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:25 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/20 23:09:10 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void genetate_philo(t_main **philos, int i)
{
	// printf("%d\n", i);
	(*philos)->philo[i].nums_time_ate = 0;
	(*philos)->philo[i].fork.right = i;
	(*philos)->philo[i].fork.left = i + 1;
}

void philo_init(t_main *philos, t_input *input)
{	
	int i = 0;
	philos->philo = malloc(sizeof(t_philo) * input->num_of_philos);
	while(i < input->num_of_philos)
	{
		genetate_philo(&philos, i);
		i++;
	}
}