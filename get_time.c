/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:24:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/27 17:40:13 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000) + (current_time.tv_usec * 0.001);
}

void isleep(int time, t_main *main)
{
	int i =0;
	while (!main->is_dead && (i < time*1000)) {
		usleep(50);
		i += 50;
	}
	// usleep(time * 1000);
}

long long	time_passed(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}