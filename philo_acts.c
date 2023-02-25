/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:09:23 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/25 22:36:19 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_thinking(t_main *main, int i)
{
	philo_status(main, i, (char *)THINKING, BLUE);
	return 1;
}
int is_sleeping(t_main *main, int i)
{
	philo_status(main, i, (char *)SLEEPING, WHITE);
	isleep(main->input.time_to_sleep);
	return 1;
}
int is_eating(t_main *main, int i)
{
	pthread_mutex_lock(&main->forks[main->philo[i].fork.left]);
	philo_status(main, i, (char *)FORK, YELLOW);
	pthread_mutex_lock(&main->forks[main->philo[i].fork.right]);
	philo_status(main, i, (char *)FORK, YELLOW);
	philo_status(main, i, (char *)EATING, GREEN);
	isleep(main->input.time_to_eat);
	main->philo[i].time_to_die = get_time();
	/*--------unlock forks---------*/
	main->input.nums_of_eat--;
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]);
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]);
	return 1;
}

void philo_status(t_main *main, int i, char *status, char *color)
{
	printf("%s %lld   %d %s\n",color, (get_time() - main->intial_time), main->philo[i].id, status);
}
