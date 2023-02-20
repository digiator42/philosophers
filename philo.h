/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:37:53 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/20 12:12:59 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_philo
{
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nums_of_eat;
	int id;
	pthread_t thread;
} t_philo;

typedef struct s_philos
{
	t_philo *philo;
} t_philos;

typedef struct s_in
{
	int *i;
	int *j;
} t_in;

/*  -> parsing <-  */
int args_error(int ac, char **av, t_philo *philo);

/*  -> utils <-  */
int	ft_atoi(const char *ptr);
int	is_valid_num(char **av);

/* -> philos_init <-*/
void philo_init(t_philos *philos, t_philo *input);


#endif