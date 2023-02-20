#include "philo.h"

int philo_input(int ac, char **av, t_input *input)
{
	if (ac == 5 || ac == 6)
	{
		input->num_of_philos = ft_atoi(av[1]);
		input->time_to_die = ft_atoi(av[2]);
		input->time_to_eat = ft_atoi(av[3]);
		input->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			input->nums_of_eat = ft_atoi(av[5]);
		else
			input->nums_of_eat = INT_MAX;
		printf("%d %d %d %d %d\n", input->num_of_philos, input->time_to_die,
			   input->time_to_eat, input->time_to_sleep, input->nums_of_eat);
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

int valid_philo(t_input *philo)
{
	if(philo->num_of_philos <= 0 || philo->time_to_die <= 0 
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0 
			|| philo->nums_of_eat <= 0)
				return 0;
	return 1;
}

int args_error(int ac, char **av, t_input *input)
{
	t_main philo;
	if(ac < 5 || ac > 6)
		return (printf("ERROR\nMust be 4 or 5 args\n"), 0);
	if (!valid_num(av) || !philo_input(ac, av, input) || !valid_philo(input))
		return (printf("ERROR\nInvalid args\n"), 0);
	philo_init(&philo, input);
	return 1;
}
