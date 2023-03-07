/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 17:21:33 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	**init_forks(int philos)
{
	t_fork	**forks;

	forks = malloc((philos + 1) * sizeof(t_fork *));
	if (forks == NULL)
		return (NULL);
	forks[philos] = NULL;
	while (--philos >= 0)
	{
		forks[philos] = malloc(sizeof(t_fork));
		pthread_mutex_init(&forks[philos]->fork, NULL);
	}
	return (forks);
}

t_philo	*init_philo(t_input *input, t_fork **forks)
{
	int		i;
	t_philo	*philo;

	philo = malloc(input->n_philos * sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < input->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_time_ate = input->start_time;
		philo[i].input = input;
		philo[i].first_fork = forks[i];
		philo[i].second_fork = forks[(i + 1) % input->n_philos];
		i++;
	}
	return (philo);
}

void	free_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		pthread_mutex_destroy(&forks[i]->fork);
		free(forks[i]);
		i++;
	}
	free(forks);
}
