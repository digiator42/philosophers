/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/25 22:37:27 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void join_philos(t_main *philos)
{
	int i = 0;
	while(i < philos->input.num_of_philos)
	{
		pthread_join(philos->philo[i].thread, NULL);
		i++;
	}
}

int philo_threads(t_main *main)
{
	int i = 0;
	while(i < main->input.num_of_philos)
	{
		if(!(i % 2))
		{
			main->philos_index = i;
			if(pthread_create(&main->philo[i].thread, NULL, &routine, main))
				return 0;
			usleep(1000);
			i++;
		}
		else
		{
			main->philos_index = i;
			pthread_create(&main->philo[i].thread, NULL, &routine, main);
			usleep(100000);
			i++;
		}
	}
	join_philos(main);
	return 1;
}	
