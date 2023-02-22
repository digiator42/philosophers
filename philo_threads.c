/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/22 16:16:50 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_status(t_main *main, int i)
{
	while(!main->philo->time_to_die)
	{
		printf("%lld   %d has taken a fork\n", (main->intial_time - get_time()), main->philo[i].id);
		break;
	}
}
 
void *routine(void *arg)
{
	t_main *main;
	int i;

	main = (t_main *)arg;
	i = main->philos_index;
	main->intial_time = get_time();
	philo_status(main, i);
	
	return arg;
}

void join_philos(t_main *philos, t_input *input)
{
	int i = 0;
	while(i < input->num_of_philos)
	{
		pthread_join(philos->philo[i].thread, NULL);
		i++;
	}
}

void philo_threads(t_main *main, t_input *input)
{
	int i = 0;
	while(i < input->num_of_philos)
	{
		main->philos_index = i;
		pthread_create(&main->philo[i].thread, NULL, &routine, main);
		usleep(150);
		i++;
	}
	join_philos(main, input);
}	
