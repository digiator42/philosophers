/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/03 17:20:07 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_input(int ac, char **av, t_main *main)
{
	if (ac == 5 || ac == 6)
	{
		main->input.num_philo = ft_atoi(av[1]);
		main->input.time_to_die = ft_atoi(av[2]);
		main->input.time_to_eat = ft_atoi(av[3]);
		main->input.time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			main->input.num_of_times_eat = ft_atoi(av[5]);
		else
			main->input.num_of_times_eat = 1000;
		return (1);
	}
	return (0);
}

int	valid_philo(t_main *main)
{
	if (main->input.num_philo <= 0 || main->input.time_to_die <= 0
		|| main->input.time_to_eat <= 0 || main->input.time_to_sleep <= 0
		|| main->input.num_of_times_eat <= 0)
		return (0);
	return (1);
}

int	args_error(int ac, char **av, t_main *main)
{
	if (ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_input(ac, av, main) || !valid_philo(main))
		return (printf("ERROR\nInvalid args\n"), 0);
	return (1);
}

void	fill_philo(t_main **philos, int i)
{
	(*philos)->philo[i].id = i + 1;
	(*philos)->philo[i].num_of_times_ate = 0;
	(*philos)->philo[i].time_to_die = 0;
	(*philos)->philo[i].fork.left = i;
	(*philos)->philo[i].fork.right = (i + 1) % (*philos)->input.num_philo;
}

int	philo_init(t_main *philos)
{
	int	i;

	i = 0;
	philos->philo = malloc(sizeof(t_philo) * philos->input.num_philo);
	if (!(philos->philo))
		return (0);
	while (i < philos->input.num_philo)
		(fill_philo(&philos, i), i++);
	return (1);
}
