#include "philo.h"

int philo_init(int ac, char **av, t_philo *philo)
{
	if (ac == 5 || ac == 6)
	{
		philo->forks = malloc(sizeof(int) * ft_atoi(av[1]));
		philo->num_of_philos = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		else
			philo->number_of_times_each_philosopher_must_eat = 1;
		printf("%d %d %d %d %d\n", philo->num_of_philos, philo->time_to_die,
			   philo->time_to_eat, philo->time_to_sleep, philo->number_of_times_each_philosopher_must_eat);
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
				if ((av[j][0] == '+' || av[j][0] == '-'))
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

int valid_philo(t_philo *philo)
{
	if(philo->num_of_philos <= 0 || philo->time_to_die <= 0 
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0 
			|| philo->number_of_times_each_philosopher_must_eat <= 0)
				return 0;
	return 1;
}

int args_error(int ac, char **av, t_philo *philo)
{
	if(ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_init(ac, av, philo) || !valid_philo(philo))
		return (printf("ERROR\ninvalid args\n"), 0);
	return 1;
}
