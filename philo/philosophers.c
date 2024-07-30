/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:32:11 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/30 14:38:41 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philo;
	t_env	env;

	if (arg_check(argc, argv))
	{
		init_env(argc, argv, &env);
		philo = malloc(sizeof(t_philo *) * env.no_philos);
		if (!philo)
			error_exit("Error: malloc failed.\n");
		init_philos(philo, &env);
		thread_create(philo, &env);
		thread_join(philo, &env);
		free(env.forks);
		free(env.forks_mutex);
		free_philos(philo, &env);
	}
	return (-1);
}
