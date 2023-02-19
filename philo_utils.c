#include "philo.h"

int	is_valid_num(char **av)
{
	int	i;
	int	j;

	j = 0;
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
			{
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	ft_atoi(const char *ptr)
{
	int					i;
	int					j;
	long long	res;

	i = 0;
	j = 1;
	res = 0;
	while (ptr[i] == ' ' || (ptr[i] >= 8 && ptr[i] <= 14))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
		if (ptr[i++] == '-')
			j *= -1;
	while (ptr[i] == '0')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
		res = (ptr[i++] - 48) + (res * 10);
	if (res > INT_MAX)
		return (-1);
	return (res * j);
}