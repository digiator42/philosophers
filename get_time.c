/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:24:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/21 14:36:48 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long convert_time(void)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("%ld %d\n", current_time.tv_sec , current_time.tv_usec);
	return current_time.tv_sec * 1000 + (int)current_time.tv_usec * 0.001;
}
