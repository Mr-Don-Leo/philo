/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:21:21 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:40:40 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief Create threads
/// @param philo 
/// @param env 
void	thread_create(t_philo **philo, t_env *env)
{
	int	index;

	index = 0;
	while (index < env->no_philos)
	{
		pthread_create(&philo[index]->philosopher, NULL, process, philo[index]);
		index++;
	}
}

/// @brief Join threads
/// @param philo 
/// @param env 
void	thread_join(t_philo **philo, t_env *env)
{
	int	index;

	index = 0;
	while (index < env->no_philos)
	{
		pthread_join(philo[index]->philosopher, NULL);
		index++;
	}
}

/// @brief Destroy mutexes
/// @param env 
void	destroy_mutex(t_env *env)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&env->print);
	pthread_mutex_destroy(&env->died_mutex);
	pthread_mutex_destroy(&env->death_check_mutex);
	pthread_mutex_destroy(&env->sync_mutex);
	while (i < env->no_philos)
	{
		pthread_mutex_destroy(&env->forks_mutex[i]);
		i++;
	}
}
