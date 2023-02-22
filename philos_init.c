/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:25 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/22 21:55:14 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_main **philos, int i)
{
	(*philos)->philo[i].id = i + 1;
	(*philos)->philo[i].nums_time_ate = 0;
	(*philos)->philo[i].time_to_die = 0;
	(*philos)->philo[i].fork.left = i;
	(*philos)->philo[i].fork.right = (i + 1) % (*philos)->input.num_of_philos;
	// printf("id %d numof of eat %d left fork %d right fork %d\n",
	// 		(*philos)->philo[i].id,
	// 		(*philos)->philo[i].nums_time_ate,
	// 		(*philos)->philo[i].fork.left,
	// 		(*philos)->philo[i].fork.right);
}

void	philo_init(t_main *philos)
{
	int i;

	i = 0;
	printf("%d\n", philos->input.num_of_philos);
	philos->philo = malloc(sizeof(t_philo) * philos->input.num_of_philos);
	while (i < philos->input.num_of_philos)
		(fill_philo(&philos, i), i++);
}

int forks_init(t_main *main)
{
	int i = 0;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_of_philos);
	if(!main->forks)
		return 0;
	while(i < main->input.num_of_philos)
		if (pthread_mutex_init(&main->forks[i++], NULL))
			return printf("mutex init issue"), 0;
	return 1;
}

int forks_destroy(t_main *main)
{
	int i = 0;
	while(i < main->input.num_of_philos)
		if (pthread_mutex_destroy(&main->forks[i++]))
			return printf("mutex destroy issue"), 0;
	return 1;
}