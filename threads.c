/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 17:00:51 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = FALSE;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	if (main->input.num_philo == 1)
	{
		philo_print(main, 1, FORK);
		philo_print(main, 1, DIED);
		return (0);
	}
	while (i < main->input.num_philo)
	{
		pthread_mutex_lock(&main->write);
		main->n_thread = i;
		pthread_mutex_unlock(&main->write);
		pthread_create(&main->philo[i].thread, NULL, &routine, (void *) main);
		i++;
		usleep(2000);
	}
	// usleep(2000);
	pthread_create(&main->orca, NULL, &checker, (void *) main);
	// i = 0;
	// while(philo_is_dead(main, &i) == FALSE)
	// {
	// 	checker((void *) main);
	// 	usleep(2000);
	// 	i++;
	// }
	if (join_threads(main) == 0)
		return (0);
	return (1);
}

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	pthread_join(main->orca, NULL);
	return (TRUE);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	// pthread_mutex_destroy(&main->write);
	return (TRUE);
}
