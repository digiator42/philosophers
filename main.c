/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:22 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/02 17:48:20 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	tmain;

	// if (!args_error(ac, av, &main) || !create_forks(&main) || !create_threads(&main))
	// 	return (1);

	if (args_error(ac, av, &tmain) == FALSE)
		return (1);
	if (philo_init(&tmain) == FALSE)
		return (1); 
	if (create_forks(&tmain) == FALSE)
		return (1);
	if (create_threads(&tmain) == FALSE)
		return (philo_free(&tmain), 1);
	destroy_threads(&tmain);
	philo_free(&tmain);
	return (0);
}
