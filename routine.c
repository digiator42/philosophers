/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:06:51 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/26 19:09:41 by ahassan          ###   ########.fr       */
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
	pthread_mutex_init(&main->die, NULL);
	//num of eat being decremented in eat func, dead status in main thread -> death checker 
	while(main->input.nums_of_eat >= 0 && main->is_dead == NO)
	{
		// printf("dead %d\n", main->is_dead);
		if(!routine_execute(main, i))
			return NULL;
	}
	return NULL;
}

int	routine_execute(t_main *main, int i)
{
	is_eating(main, i);

	is_sleeping(main, i);
	is_thinking(main, i);
	return (1);
}

int	philo_is_dead(t_main *main, int *i)
{
	long long	time_passed;

	if (*i == main->input.num_of_philos)
		*i = 0;
	time_passed = get_time() - main->philo[*i].time_to_die;
	printf("%lld\n", time_passed);
	if (time_passed > main->input.time_to_die)
	{
		printf("DDDDDIED");
		philo_status(main, main->philo[*i].id, DIED, RED);
		main->is_dead = YES;
		return (1);
	}
	printf("is incremented %d\n", *i);
	(*i)++;
	return (0);
}

void *death_checker(void *args)
{
	t_main *main;
	int i = 0;
	main = (t_main *)args;
		
	while (main->input.nums_of_eat >= 0 && main->is_dead == NO)
	{
		if (philo_is_dead(main, &i) == YES)
			break ;
	}
	return 0;
}