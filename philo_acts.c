/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/02 20:37:12 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_main *main, int *i)
{
	if (main->philo[*i].id % 2)
	{
		pthread_mutex_lock(&main->forks[main->philo[*i].fork.left]);
		pthread_mutex_lock(&main->forks[main->philo[*i].fork.right]);
		philo_print(main, main->philo[*i].id, FORK);
		philo_print(main, main->philo[*i].id, FORK);
	}
	else
	{
		pthread_mutex_lock(&main->forks[main->philo[*i].fork.right]);
		pthread_mutex_lock(&main->forks[main->philo[*i].fork.left]);
		philo_print(main, main->philo[*i].id, FORK);
		philo_print(main, main->philo[*i].id, FORK);
	}
}

int	philo_eat(t_main *main, int i)
{
	take_fork(main, &i);
	philo_print(main, main->philo[i].id, EAT);
	pthread_mutex_lock(&main->write);
	main->philo[i].time_to_die = get_time();
	pthread_mutex_unlock(&main->write);
	exec_action(main->input.time_to_eat);
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]);
	pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]);
	pthread_mutex_lock(&main->write);
	main->philo[i].num_of_times_ate++;
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	pthread_mutex_lock(&main->write);
	time = delta_time(main->philo[*i].time_to_die);
	pthread_mutex_unlock(&main->write);
	if (time >= main->input.time_to_die && get_time_to_die(main, main->input.time_to_die,
			main->input.time_to_eat))
	{
		philo_print(main, main->philo[*i].id, DIED);
		pthread_mutex_lock(&main->write);
		main->philo_dead = TRUE;
		pthread_mutex_unlock(&main->write);
		return (TRUE);
	}
	return (FALSE);
}
