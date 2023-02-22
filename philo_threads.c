/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/22 20:30:01 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_eating(t_main *main, int i)
{
	pthread_mutex_lock(&main->forks[main->philo[i].fork.left]);
	printf("%lld   %d has taken a fork\n", (get_time() - main->intial_time), main->philo[i].id);
	pthread_mutex_lock(&main->forks[main->philo[i].fork.right]);
	printf("%lld   %d has taken a fork\n", (get_time() - main->intial_time), main->philo[i].id);
	// isleep(input.time_to_eat);
	/*--------unloc forks---------*/
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]);
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]);
	main->philo->nums_of_eat--;
	return 0;
}

int	routine_execute(t_main *main, int i)
{
	is_eating(main, i);
	if (!main->philo->nums_time_ate)
	{
		// is_sleeping(main, i);
		// is_thinking(main, i);
	}
	return (1);
}
void philo_status(t_main *main, int i)
{
	while(main->philo->nums_of_eat)
	{
		routine_execute(main, i);
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

void join_philos(t_main *philos)
{
	int i = 0;
	while(i < philos->input.num_of_philos)
	{
		pthread_join(philos->philo[i].thread, NULL);
		i++;
	}
}

void philo_threads(t_main *main)
{
	int i = 0;
	main->philo->nums_of_eat = main->input.nums_of_eat;
	while(i < main->input.num_of_philos)
	{
		main->philos_index = i;
		pthread_create(&main->philo[i].thread, NULL, &routine, main);
		usleep(150);
		i++;
	}
	join_philos(main);
}	
