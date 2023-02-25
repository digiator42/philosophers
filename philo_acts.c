/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:09:23 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/25 20:09:34 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_thinking(t_main *main, int i)
{
	printf("\e[1;34m%lld   %d is thinking\e[0m\n", (get_time() - main->intial_time), main->philo[i].id);
	usleep(50000);
	return 1;
}
int is_sleeping(t_main *main, int i)
{
	printf("\e[1;37m%lld   %d is sleeping\e[0m\n", (get_time() - main->intial_time), main->philo[i].id);
	isleep(main->input.time_to_sleep);
	return 1;
}
int is_eating(t_main *main, int i)
{
	pthread_mutex_lock(&main->forks[main->philo[i].fork.left]);
	printf("\e[0;33m%lld   %d has taken a fork\n", (get_time() - main->intial_time), main->philo[i].id);
	pthread_mutex_lock(&main->forks[main->philo[i].fork.right]);
	printf("\e[0;33m%lld   %d has taken a fork\n", (get_time() - main->intial_time), main->philo[i].id);
	printf("\e[0;32m%lld   %d is eating\n", (get_time() - main->intial_time), main->philo[i].id);
	isleep(main->input.time_to_eat);
	main->philo[i].time_to_die = get_time();
	/*--------unlock forks---------*/
	main->input.nums_of_eat--;
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]);
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]);
	return 1;
}