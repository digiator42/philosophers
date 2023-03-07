/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 16:55:45 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *place)
{
	t_philo	*philo;

	philo = (t_philo *)place;
	if (philo->input->n_philos == 1)
	{
		philo_print(TAKE_FORK, philo);
		exec_action(philo->input->time_to_die);
		return (NULL);
	}
	while (philo_is_dead(philo) == FALSE)
	{
		eating(philo);
		if (philo->meals == philo->input->num_of_eats)
		{
			pthread_mutex_lock(&philo->input->full);
			philo->input->done_eating++;
			pthread_mutex_unlock(&philo->input->full);
			return (NULL);
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	declare_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->notify);
	philo->input->death = TRUE;
	pthread_mutex_unlock(&philo->input->notify);
	philo_print(DEAD, philo);
}

void	*checker(void *arg)
{
	int		i;
	t_philo	*philos;

	philos = *(t_philo **)arg;
	while (reached_nums_of_ate(philos->input) == FALSE)
	{
		i = 0;
		while (i < philos->input->n_philos)
		{
			if (philo_starved(&philos[i]))
				return (declare_death(&philos[i]), NULL);
			i++;
		}
		usleep(2500);
	}
	return (NULL);
}

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->notify);
	if (philo->input->death)
	{
		pthread_mutex_unlock(&philo->input->notify);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->input->notify);
	return (FALSE);
}
