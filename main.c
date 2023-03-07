/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 16:54:16 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input	input;
	t_fork	**forks;
	t_philo	*philos;

	if (!args_error(argc, argv, &input))
		return (1);
	if (!philo_input(argc, argv, &input))
		return (1);
	forks = init_forks(input.n_philos);
	if (!forks)
		return (1);
	philos = init_philo(&input, forks);
	if (!philos)
		return (1);
	creat_threads(&input, philos);
	free(philos);
	free_forks(forks);
	return (0);
}
