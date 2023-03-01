/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 16:59:35 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (FALSE);
	if (philo_is_dead(main, &i) == TRUE)
		return 0;
	if (philo_print(main, main->philo[i].id, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, FORK) == FALSE)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, EAT) == FALSE)
		return (FALSE);
	main->philo[i].time_to_die = get_time();
	// printf("dead time in philo aldakhlawy %lld\n", main->philo[0].time_to_die);
	exec_action(main->input.time_to_eat);
	drop_forks(main, i);
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_is_dead(main, &i) == TRUE)
		return 0;
	if (philo_print(main, main->philo[i].id, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->input.time_to_sleep);
	return (TRUE);
}

int is(int die, int sleep)
{
	int i = 2;
	while(i < sleep / 2)
	{
		if (die > sleep * i)
			return 0;
		i++;
	}
	return 1;
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
	time = delta_time(main->philo[*i].time_to_die);
	//(main->input.num_of_times_eat * main->input.num_philo) > main->num_of_times_ate
	if (time >= main->input.time_to_die && is(main->input.time_to_die, main->input.time_to_eat))
	{
		philo_print(main, main->philo[*i].id, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	main->num_of_times_ate++;
	return (TRUE);
}

//time >= main->input.time_to_die && main->input.time_to_die <= main->input.time_to_sleep