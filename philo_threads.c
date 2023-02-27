/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/27 19:45:06 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void join_philos(t_main *philos)
{
	int i = 0;
	// printf("nums of philos %d\n", philos->input.num_of_philos);
	while(i < philos->input.num_of_philos)
	{
		pthread_join(philos->philo[i].thread, NULL);
		i++;
	}
	pthread_join(philos->death, NULL);
}

int philo_threads(t_main *main)
{
	int i = 0;
	main->is_dead = NO;
	main->intial_time = get_time();
	pthread_mutex_init(&main->die, NULL);
	while(i < main->input.num_of_philos)
	{
		main->philos_index = i;
		pthread_create(&main->philo[i].thread, NULL, &routine, main);
		i++;
		usleep(1000);
	}
	pthread_create(&main->death, NULL, &death_checker, main);
	// if (pthread_mutex_init(&main->die, NULL) != 0)
	// 	return (0);
	usleep(1000);
	join_philos(main);
	return 1;
}	
