/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 16:53:00 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define FORK "%ld %d has taken a fork\n"
# define EAT "%ld %d is eating\n"
# define SLEEP "%ld %d is sleeping\n"
# define THINK "%ld %d is thinking\n"
# define DEATH "%ld %d died\n"

enum
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
};

typedef struct s_input
{
	size_t			start_time;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eats;
	int				done_eating;
	int				death;
	pthread_mutex_t	notify;
	pthread_mutex_t	log;
	pthread_mutex_t	eat;
	pthread_mutex_t	full;
}					t_input;

typedef struct s_fork
{
	pthread_mutex_t	fork;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				meals;
	size_t			last_time_ate;
	pthread_t		death;
	pthread_t		*threads;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_input			*input;
}					t_philo;

int					*parse(int argc, char **argv);
void				*checker(void *arg);
void				*routine(void *place);
int					philo_starved(t_philo *philo);
int					reached_nums_of_ate(t_input *input);
int					philo_input(int argc, char **argv, t_input *common);
void				creat_threads(t_input *input, t_philo *philo);
t_fork				**init_forks(int philos);
int					valid_num(char **av);
int					ft_atoi(const char *ptr);
void				free_forks(t_fork **forks);
t_philo				*init_philo(t_input *input, t_fork **forks);
void				eating(t_philo *philo);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
int					philo_is_dead(t_philo *philo);
size_t				philo_print(int state, t_philo *philo);
size_t				get_current_time(void);
void				exec_action(size_t ms_time);
int					min(int a, int b);
int					max(int a, int b);
int					args_error(int ac, char **av, t_input *input);
int					ft_atoi(const char *ptr);
int					valid_num(char **av);
size_t				get_current_time(void);
void				exec_action(size_t ms_time);

#endif
