/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:25 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/20 11:14:10 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	printf("hi from routine %d\n", *(int*)arg);
	return NULL;
}

void philo_init(t_philos *philos, t_philo *input)
{
	t_in in;
	
	in.i = (int*)malloc(sizeof(int));
	in.j = (int*)malloc(sizeof(int));
	*in.i = 0;
	*in.j = 0;
	philos = malloc(sizeof(t_philos) * input->num_of_philos);
	while(*in.i < input->num_of_philos)
	{
		if(*in.i % 2 == 0)
		{
			pthread_create(&philos[*in.i].thread, NULL, &routine, in.i);
			usleep(150);
		}
		else
		{
			pthread_create(&philos[*in.i].thread, NULL, &routine, in.i);
			usleep(150);
		}
		(*in.i)++;
	}
}	