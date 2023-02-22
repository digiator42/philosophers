/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:19 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/22 20:30:30 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_input(int ac, char **av, t_main *main)
{
	if (ac == 5 || ac == 6)
	{
		main->input.num_of_philos = ft_atoi(av[1]);
		main->input.time_to_die = ft_atoi(av[2]);
		main->input.time_to_eat = ft_atoi(av[3]);
		main->input.time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			main->input.nums_of_eat = ft_atoi(av[5]);
		else
			main->input.nums_of_eat = INT_MAX;
		// printf("%d %d %d %d %d\n", main->input.num_of_philos, main->input.time_to_die,
		// 	   main->input.time_to_eat, main->input.time_to_sleep, main->input.nums_of_eat);
		return 1;
	}
	return 0;
}

int	valid_num(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (i == 0)
				if ((av[j][i] == '+' || av[j][i] == '-'))
					i++;
			if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int valid_philo(t_main *main)
{
	if(main->input.num_of_philos <= 0 || main->input.time_to_die <= 0 
		|| main->input.time_to_eat <= 0 || main->input.time_to_sleep <= 0 
			|| main->input.nums_of_eat <= 0)
				return 0;
	return 1;
}

int args_error(int ac, char **av)
{
	t_main *main;
	
	main = malloc(sizeof(t_main) * 1);
	if(ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_input(ac, av, main) || !valid_philo(main))
		return (printf("ERROR\nInvalid args\n"), 0);
	philo_init(main);
	if(!forks_init(main))
		return 0;
	philo_threads(main);
	return 1;
}
