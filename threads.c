/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 16:55:53 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_threads(t_input *input, t_philo *philo)
{
	int	i;

	philo->threads = malloc(input->n_philos * sizeof(pthread_t));
	if (!philo->threads)
		return ;
	i = 0;
	while (i < input->n_philos)
	{
		pthread_create(philo->threads + i, NULL, routine, philo + i);
		i++;
	}
	pthread_create(&philo->death, NULL, checker, &philo);
	i = 0;
	while (i < input->n_philos)
		pthread_join(philo->threads[i++], NULL);
	pthread_join(philo->death, NULL);
	free(philo->threads);
}

int	philo_starved(t_philo *philo)
{
	int	last_meal;

	pthread_mutex_lock(&philo->input->eat);
	last_meal = get_current_time() - philo->last_time_ate;
	pthread_mutex_unlock(&philo->input->eat);
	return (last_meal > philo->input->time_to_die);
}

int	reached_nums_of_ate(t_input *input)
{
	pthread_mutex_lock(&input->full);
	if (input->done_eating == input->n_philos)
		return (TRUE);
	pthread_mutex_unlock(&input->full);
	return (FALSE);
}
