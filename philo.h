/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 17:00:35 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"


typedef struct s_input
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	long long		time_to_die;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	int				num_of_times_ate;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_main;

/* actions.c */
int			philo_eat(t_main *main, int i);
int			philo_sleep(t_main *main, int i);
int			philo_think(t_main *main, int i);
int			philo_is_dead(t_main *main, int *i);
int			drop_forks(t_main *main, int i);

/*
** handling_errors.c
*/
int			error_handling(int argc, char **argv, t_main *main);
int			init_input_struct(int argc, char **argv, t_main *main);
void		print_args_errors(t_main *main, int argc);
void	philo_init(t_main *philos);
int args_error(int ac, char **av, t_main *main);

/*
** handling_forks.c
*/
int			create_forks(t_main *main);
void		unlock_forks(t_main *main);

/*
** handling_philos.c
*/
int			create_philos(t_main *main);
void		fill_philo_struct(t_main *main, int i, int j);

/*
** handling_threads.c
*/
int			create_threads(t_main *main);
int			join_threads(t_main *main);
int			destroy_threads(t_main *main);

/*
** handling_time.c
*/
long long	get_time(void);
long long	delta_time(long long time2);
void		exec_action(long long time);

/*
** philo_utils.c
*/
int	is_valid_num(char **av);
int	ft_atoi(const char *ptr);
int			philo_strlen(const char *str);
void		philo_free(t_main *main);

/*
** routine.c
*/
void		*routine(void *args);
int			routine_execute(t_main *main, int i);
void		*checker(void *args);
int			philo_print(t_main *main, int id, char *status);

#endif