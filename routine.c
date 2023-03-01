/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 17:06:53 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while ((main->input.num_of_times_eat * main->input.num_philo) > main->num_of_times_ate)
		{
			if(main->philo_dead == TRUE)
				return NULL;
			routine_execute(main, i);
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (routine_execute(main, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	if (main->input.num_of_times_eat != main->num_of_times_ate)
	{
		if (philo_sleep(main, i) == FALSE)
			return (FALSE);
		if (philo_think(main, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	*checker(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->input.num_of_times_eat > 0)
	{
		while ((main->input.num_of_times_eat * main->input.num_philo) > main->num_of_times_ate
			&& main->philo_dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_main *main, int id, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	if (main->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&main->write);
		return (FALSE);
	}
	else
		printf("%lld %d %s\n", now, id, status);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}
