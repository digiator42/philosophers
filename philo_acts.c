/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:09:23 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/27 19:47:16 by ahassan          ###   ########.fr       */
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
	isleep(main->input.time_to_sleep, main);
	return 1;
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (0);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (0);
	return (1);
}

int is_eating(t_main *main, int i)
{
	pthread_mutex_lock(&(main->forks[main->philo[i].fork.left]));
	philo_status(main, i, (char *)FORK, YELLOW);
	pthread_mutex_lock(&(main->forks[main->philo[i].fork.right]));
	philo_status(main, i, (char *)FORK, YELLOW);
	philo_status(main, i, (char *)EATING, GREEN);
	main->philo[i].time_to_die = get_time();
	isleep(main->input.time_to_eat, main);
	// printf("%lld\n", main->philo[i].time_to_die);
	/*--------unlock forks---------*/
	drop_forks(main, i);
	// pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]);
	// pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]);
	main->input.nums_of_eat--;
	return 1;
}

void philo_status(t_main *main, int i, char *status, char *color)
{
	long long	now;

	now = get_time() - main->intial_time;
	pthread_mutex_lock(&main->die);
	if (main->is_dead == YES)
	{
		pthread_mutex_unlock(&main->die);
		return ;
	}
	else
		printf("%s %lld   %d %s\n",color, (get_time() - main->intial_time), main->philo[i].id, status);
	pthread_mutex_unlock(&main->die);
}
