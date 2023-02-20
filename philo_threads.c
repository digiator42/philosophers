/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/20 22:35:57 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *routine(void *arg)
// {
// 	printf("hi from routine %d\n", *(int*)arg);
// 	return arg;
// }

// void join_philos(t_main *philos, t_input *input,  t_in *in)
// {
// 	*in->i = 0;
// 	int *res;
// 	while(*in->i < input->num_of_philos)
// 	{
// 		pthread_join(philos->philo[*in->i].thread, (void *)&res);
// 		printf("got res %d from philo id %d\n", (int)res, philos->philo[*in->i].id);
// 		(*in->i)++;
// 	}
// }

// void philo_threads(t_main *philos, t_philo *input)
// {
// 	t_in in;
	
// 	in.i = (int*)malloc(sizeof(int));
// 	in.j = (int*)malloc(sizeof(int));
	
// 	*in.i = 0;
// 	*in.j = 0;
// 	while(*in.i < input->num_of_philos)
// 	{
// 		if(!(*in.i % 2))
// 		{
// 			philos->philo[*in.i].id = *in.i + 1;
// 			pthread_create(&philos->philo[*in.i].thread, NULL, &routine, in.i);
// 			usleep(150);
// 			printf("my ID %d\n", philos->philo[*in.i].id);
// 		}
// 		else
// 		{
// 			philos->philo[*in.i].id = *in.i + 1;
// 			pthread_create(&philos->philo[*in.i].thread, NULL, &routine, in.i);
// 			usleep(150);
// 			printf("my ID %d\n", philos->philo[*in.i].id);
// 		}
// 		(*in.i)++;
// 	}
// 	join_philos(philos, input, &in);
// }	
