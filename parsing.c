/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 17:06:14 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_input(int ac, char **av, t_main *main)
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
			main->input.num_of_times_eat = 200;
		// printf("%d %d %d %d %d\n", main->input.num_philo, main->input.time_to_die,
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
	if(main->input.num_philo <= 0 || main->input.time_to_die <= 0 
		|| main->input.time_to_eat <= 0 || main->input.time_to_sleep <= 0 
			|| main->input.num_of_times_eat <= 0)
				return 0;
	return 1;
}

int args_error(int ac, char **av, t_main *main)
{
	if(ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_input(ac, av, main) || !valid_philo(main))
		return (printf("ERROR\nInvalid args\n"), 0);
	return 1;
}

void	fill_philo(t_main **philos, int i)
{
	(*philos)->philo[i].id = i + 1;
	(*philos)->philo[i].num_of_times_ate = 0;
	(*philos)->philo[i].time_to_die = 0;
	(*philos)->philo[i].fork.left = i;
	(*philos)->philo[i].fork.right = (i + 1) % (*philos)->input.num_philo;
	// printf("id %d numof of eat %d left fork %d right fork %d\n",
	// 		(*philos)->philo[i].id,
	// 		(*philos)->philo[i].num_of_times_ate,
	// 		(*philos)->philo[i].fork.left,
	// 		(*philos)->philo[i].fork.right);
}

int	philo_init(t_main *philos)
{
	int i;

	i = 0;
	printf("here %d\n", philos->input.num_philo);
	philos->philo = malloc(sizeof(t_philo) * philos->input.num_philo);
	if(!(philos->philo))
		return 0;
	while (i < philos->input.num_philo)
		(fill_philo(&philos, i), i++);
	printf("i at the end %d\n", i);
	return 1;	
}
// int	create_philos(t_main *main)
// {
// 	int	i;
// 	int	j;

// 	main->philo = malloc(sizeof(t_philo) * (main->input.num_philo) + 1);
// 	if (main->philo == NULL)
// 		return (FALSE);
// 	i = 0;
// 	j = 1;
// 	while (j < main->input.num_philo)
// 	{
// 		fill_philo_struct(main, i, j);
// 		i++;
// 		j++;
// 	}
// 	j = 0;
// 	fill_philo_struct(main, i, j);
// 	return (TRUE);
// }

// void	fill_philo_struct(t_main *main, int i, int j)
// {
// 	main->philo[i].id = i + 1;
// 	main->philo[i].num_of_times_ate = 0;
// 	main->philo[i].time_to_die = 0;
// 	main->philo[i].fork.left = i;
// 	main->philo[i].fork.right = j;
// }
