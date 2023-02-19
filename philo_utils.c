#include "philo.h"

int	ft_atoi(const char *ptr)
{
	int					i;
	int					j;
	int					count;
	unsigned long long	res;

	i = 0;
	j = 1;
	count = 0;
	res = 0;
	while (ptr[i] == ' ' || (ptr[i] >= 8 && ptr[i] <= 14))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
		if (ptr[i++] == '-')
			j *= -1;
	while (ptr[i] == '0')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = (ptr[i++] - 48) + (res * 10);
		count++;
	}
	if (res >= __LONG_LONG_MAX__ || count > 19)
		return (-(j == 1));
	return (res * j);
}