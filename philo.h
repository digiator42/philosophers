/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:37:53 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/25 20:19:33 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_input
{
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nums_of_eat;
} t_input;

typedef struct s_fork
{
	int left;
	int right;
} t_fork;

typedef struct s_philo
{
	int id;
	int nums_time_ate;
	int nums_of_eat;
	int time_to_die;
	pthread_t thread;
	t_fork fork;
	
} t_philo;

typedef struct s_main
{
	t_philo *philo;
	long long intial_time;
	int philos_index;
	pthread_mutex_t tmp;
	pthread_mutex_t *forks;
	t_input input;
} t_main;

/* -> routine <-*/
int philo_status(t_main *main, int i);
void *routine(void *arg);

/*  -> parsing <-  */
int args_error(int ac, char **av);

/*  -> utils <-  */
int	ft_atoi(const char *ptr);
int	is_valid_num(char **av);

/* -> philos_threads <-*/
int philo_threads(t_main *main);

/* -> philos_init <-*/
void philo_init(t_main *philos);
int forks_init(t_main *main);

/* -> philos_init <-*/
long long get_time(void);


/* -> philo_acts <-*/
int is_eating(t_main *main, int i);
int is_sleeping(t_main *main, int i);
int is_thinking(t_main *main, int i);

/* -> get time <-*/
void isleep(int time);

#endif