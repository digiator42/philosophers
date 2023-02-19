#include "philo.h"

int args_error(int ac, char **av, t_philo *philo)
{
	(void)(av);

	philo = malloc(sizeof(t_philo) * 1);
	if(ac == 5 || ac == 6)
	{
		philo->forks = malloc(sizeof(int) * ft_atoi(av[1]));
		philo->num_of_philos = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_sleep = ft_atoi(av[3]);
		philo->time_to_eat = ft_atoi(av[4]);
		printf("%d %d %d %d", philo->num_of_philos, philo->time_to_eat, 
				philo->time_to_sleep, philo->time_to_die);
		return 1;
	}
	return 0;
}