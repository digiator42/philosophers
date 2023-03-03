/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/03 14:29:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	get_time_to_die(t_main *tmain, int time_die, int time_sleep)
{
	while (tmain->input.num_of_times_ate < (time_sleep / 2))
	{
		if (time_die > time_sleep * tmain->input.num_of_times_ate)
			return (0);
		tmain->input.num_of_times_ate++;
	}
	return (1);
}

int	ft_atoi(const char *ptr)
{
	int			i;
	int			j;
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

void	philo_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}
