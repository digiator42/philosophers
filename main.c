/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/03 14:56:07 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	tmain;

	if (!args_error(ac, av, &tmain) || !philo_init(&tmain))
		return (1);
	if (!create_forks(&tmain))
		return (1);
	if (!create_threads(&tmain))
		return (philo_free(&tmain), 0);
	destroy_threads(&tmain);
	philo_free(&tmain);
	return (0);
}
