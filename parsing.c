/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 17:29:28 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_input(int ac, char **av, t_input *input)
{
	input->start_time = get_current_time();
	input->n_philos = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	input->death = FALSE;
	input->done_eating = 0;
	if (ac == 6)
		input->num_of_eats = ft_atoi(av[5]);
	else
		input->num_of_eats = 42 * 42;
	pthread_mutex_init(&input->log, NULL);
	pthread_mutex_init(&input->notify, NULL);
	pthread_mutex_init(&input->eat, NULL);
	pthread_mutex_init(&input->full, NULL);
	return (1);
}

int	valid_philo(t_input *input)
{
	if (input->n_philos <= 0 || input->time_to_die <= 0
		|| input->time_to_eat <= 0 || input->time_to_sleep <= 0
		|| input->num_of_eats <= 0)
		return (0);
	return (1);
}

int	args_error(int ac, char **av, t_input *input)
{
	if (ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_input(ac, av, input) || !valid_philo(input))
		return (printf("ERROR\nInvalid args\n"), 0);
	return (1);
}
