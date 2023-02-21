/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:43:25 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/21 13:32:38 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_main **philos, t_input *input, int i)
{
	(*philos)->philo[i].id = i + 1;
	(*philos)->philo[i].nums_time_ate = 0;
	(*philos)->philo[i].fork.left = i;
	(*philos)->philo[i].fork.right = (i + 1) % (*philos)->philo->input.num_of_philos;
	printf("id %d numof of eat %d left fork %d right fork %d\n",
			(*philos)->philo[i].id,
			(*philos)->philo[i].nums_time_ate,
			(*philos)->philo[i].fork.left,
			(*philos)->philo[i].fork.right);
}

void	philo_init(t_main *philos, t_input *input)
{
	int i;

	i = 0;
	philos->philo = malloc(sizeof(t_philo) * input->num_of_philos);
	while (i < input->num_of_philos)
		(fill_philo(&philos, input, i), i++);
}

int forks_init(t_main *main)
{
	int i = 0;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->philo->input.num_of_philos);
	while(i < main->philo->input.num_of_philos)
		if (!pthread_mutex_init(&main->forks[i], NULL))
			return FORKS_FAIL;
	return SUCCESS;
}