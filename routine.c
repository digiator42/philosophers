/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/02 19:52:01 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*tmain;
	int		i;

	tmain = (t_main *)args;
	pthread_mutex_lock(&tmain->write);
	i = tmain->n_thread;
	pthread_mutex_unlock(&tmain->write);
	if (tmain->input.num_of_times_eat > 0)
	{
		while (tmain->input.num_of_times_eat > tmain->philo[i].num_of_times_ate)
		{
			pthread_mutex_lock(&tmain->write);
			if(tmain->philo_dead == TRUE){
				pthread_mutex_unlock(&tmain->write);
				break;
			}
			pthread_mutex_unlock(&tmain->write);
			routine_execute(tmain, i);
		}
	}
	else
	{
		while (tmain->philo_dead == FALSE)
		{
			if (routine_execute(tmain, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	if (main->input.num_of_times_eat != main->philo[i].num_of_times_ate)
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
	t_main	*tmain;
	int		i;

	tmain = (t_main *)args;
	i = 0;
	if (tmain->input.num_of_times_eat > 0)
	{
		while (tmain->philo_dead == FALSE)
		{
			if (philo_is_dead(tmain, &i) == TRUE)
				break ;
			pthread_mutex_lock(&tmain->write);
			if (tmain->input.num_of_times_eat <= tmain->philo[i].num_of_times_ate) 
			{
				pthread_mutex_unlock(&tmain->write);
				break ;
			}
			pthread_mutex_unlock(&tmain->write);
		}
	}
	else
	{
		while (tmain->philo_dead == FALSE)
		{
			if (philo_is_dead(tmain, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_main *main, int id, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&main->write);
		return (FALSE);
	}
	printf("%lld %d %s\n", now, id, status);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}
