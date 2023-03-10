/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 16:57:11 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	philo_print(int state, t_philo *philo)
{
	size_t	now;
	size_t	passed;

	pthread_mutex_lock(&philo->input->log);
	now = get_current_time();
	passed = now - philo->input->start_time;
	if (state == EATING)
		printf(FORK FORK EAT, passed, philo->id, passed, philo->id, passed,
			philo->id);
	else if (state == TAKE_FORK)
		printf(FORK, passed, philo->id);
	else if (state == SLEEPING)
		printf(SLEEP, passed, philo->id);
	else if (state == THINKING)
		printf(THINK, passed, philo->id);
	else if (state == DEAD)
		printf(DEATH, passed, philo->id);
	pthread_mutex_unlock(&philo->input->log);
	return (now);
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
