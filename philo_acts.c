/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/07 17:22:33 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->first_fork->fork);
		pthread_mutex_lock(&philo->second_fork->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->second_fork->fork);
		pthread_mutex_lock(&philo->first_fork->fork);
	}
	if (philo_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->first_fork->fork);
		pthread_mutex_unlock(&philo->second_fork->fork);
		return ;
	}
	philo->meals++;
	pthread_mutex_lock(&philo->input->eat);
	philo->last_time_ate = philo_print(EATING, philo);
	pthread_mutex_unlock(&philo->input->eat);
	exec_action(philo->input->time_to_eat);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
	return ;
}

void	sleeping(t_philo *philo)
{
	if (philo_is_dead(philo))
		return ;
	philo_print(SLEEPING, philo);
	exec_action(philo->input->time_to_sleep);
	return ;
}

void	thinking(t_philo *philo)
{
	if (philo_is_dead(philo))
		return ;
	philo_print(THINKING, philo);
	return ;
}
