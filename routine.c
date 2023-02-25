/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:06:51 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/25 20:20:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	t_main *main;
	int i;

	main = (t_main *)arg;
	i = main->philos_index;
	main->intial_time = get_time();
	if(!philo_status(main, i))
		return 0;
	
	return arg;
}

int	routine_execute(t_main *main, int i)
{
	is_eating(main, i);
	usleep(500000);
	if (!main->philo->nums_time_ate)
	{
		is_sleeping(main, i);
		if (!is_thinking(main, i))
			return 0;
	}
	return (1);
}
int philo_status(t_main *main, int i)
{
	pthread_mutex_init(&main->tmp, NULL);
	while(1)
	{
		// printf("nums of eat %d\n", main->input.nums_of_eat);
		if(main->input.nums_of_eat <= 0)
			break;
		if(!routine_execute(main, i))
			return 0;
	}
	return 1;
}

