/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:37:53 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/20 23:05:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_input
{
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nums_of_eat;
	int id;
	pthread_t thread;
} t_input;

typedef struct s_fork
{
	int left;
	int right;
} t_fork;

typedef struct s_philo
{
	int nums_time_ate;
	t_fork fork;
	
} t_philo;

typedef struct s_main
{
	t_philo *philo;
} t_main;


/*  -> parsing <-  */
int args_error(int ac, char **av, t_input *input);

/*  -> utils <-  */
int	ft_atoi(const char *ptr);
int	is_valid_num(char **av);

/* -> philos_threads <-*/
void philo_threads(t_main *philos, t_philo *input);

/* -> philos_init <-*/
void philo_init(t_main *philos, t_input *input);

#endif