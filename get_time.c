/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/01 16:58:58 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec * 0.001));
}

long long	delta_time(long long time)
{
	// pthread_mutex_lock(&main->write);
	if (time > 0)
	{
		// pthread_mutex_unlock(&main->write);
		return (get_time() - time);
	}
	// pthread_mutex_unlock(&main->write);
	return (0);
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}
