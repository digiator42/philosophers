/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 16:59:07 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_main *main)
{
	int	i;
	printf("forks %d\n", main->input.num_philo);
	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo);
	if (main->forks == NULL)
		return (FALSE);
	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

