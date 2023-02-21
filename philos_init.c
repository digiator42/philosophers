/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:25 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/21 12:43:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void genetate_philo(t_main **philos, t_input *input, int i)
{
	// printf("%d\n", i);
	(*philos)->philo[i].id = i + 1;
	(*philos)->philo[i].nums_time_ate = 0;
	(*philos)->philo[i].fork.left = i;
	(*philos)->philo[i].fork.right = (i + 1) % (input->num_of_philos);
	printf("id %d numof of eat %d left fork %d right fork %d\n", 
		(*philos)->philo[i].id, (*philos)->philo[i].nums_time_ate,
		(*philos)->philo[i].fork.left, (*philos)->philo[i].fork.right);
}

void philo_init(t_main *philos, t_input *input)
{	
	int i = 0;
	philos->philo = malloc(sizeof(t_philo) * input->num_of_philos);
	while(i < input->num_of_philos)
	{
		genetate_philo(&philos, input, i);
		i++;
	}
}