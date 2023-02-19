#include "philo.h"

int philo_init(int ac, char **av, t_philo *philo)
{
	philo = malloc(sizeof(t_philo) * 1);
	if(ac == 5 || ac == 6)
	{
		philo->forks = malloc(sizeof(int) * ft_atoi(av[1]));
		philo->num_of_philos = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		if(ac == 6)
			philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		else
			philo->number_of_times_each_philosopher_must_eat = 1;
		printf("%d %d %d %d %d", philo->num_of_philos, philo->time_to_die, 
				philo->time_to_eat, philo->time_to_sleep, philo->number_of_times_each_philosopher_must_eat);
		return 1;
	}
	return 0;
}

int args_error(int ac, char **av, t_philo *philo)
{
	if(!philo_init(ac, av, philo))
		return (printf("ERROR\ninvalid args\n"), 0);
	return 1;	
}
