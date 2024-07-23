/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:44:57 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:04:46 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	right_fork(t_philo *philo)
{
	int	fork_index;

	fork_index = philo->index - 1;
	pthread_mutex_lock(&philo->env->forks_mutex[fork_index]);
	if (!philo->env->forks[fork_index])
	{
		pthread_mutex_unlock(&philo->env->forks_mutex[fork_index]);
		return (0);
	}
	pthread_mutex_lock(&philo->env->sync_mutex);
	if (value_check(philo->env->died, philo->env->died_mutex))
	{
		pthread_mutex_unlock(&philo->env->sync_mutex);
		pthread_mutex_unlock(&philo->env->forks_mutex[fork_index]);
		return (0);
	}
	pthread_mutex_unlock(&philo->env->sync_mutex);
	print(philo, &philo->env->print, FORK);
	philo->env->forks[fork_index] = 0;
	pthread_mutex_unlock(&philo->env->forks_mutex[fork_index]);
	return (1);
}

int	left_fork(t_philo *philo)
{
	int	id;

	if (philo->index == 1)
		id = philo->env->no_philos - 1;
	else
		id = philo->index - 2;
	pthread_mutex_lock(&philo->env->forks_mutex[id]);
	if (!philo->env->forks[id])
	{
		pthread_mutex_unlock(&philo->env->forks_mutex[id]);
		return (0);
	}
	pthread_mutex_lock(&philo->env->sync_mutex);
	if (value_check(philo->env->died, philo->env->died_mutex))
	{
		pthread_mutex_unlock(&philo->env->forks_mutex[id]);
		pthread_mutex_unlock(&philo->env->sync_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->env->sync_mutex);
	print(philo, &philo->env->print, FORK);
	philo->env->forks[id] = 0;
	pthread_mutex_unlock(&philo->env->forks_mutex[id]);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (!philo->right_fork && right_fork(philo))
		philo->right_fork = 1;
	if (!philo->left_fork && left_fork(philo))
		philo->left_fork = 1;
	if (philo->right_fork && philo->left_fork)
		return (1);
	return (0);
}

/// @brief The leave_forks function is called when the philosopher is
///        done eating, it releases the forks that the philosopher was holding.
/// @param philo
void	leave_forks(t_philo *philo)
{
	int	left_fork_index;

	if (philo->right_fork)
	{
		philo->right_fork = 0;
		pthread_mutex_lock(&philo->env->forks_mutex[philo->index - 1]);
		philo->env->forks[philo->index - 1] = 1;
		pthread_mutex_unlock(&philo->env->forks_mutex[philo->index - 1]);
	}
	if (philo->index == 1)
		left_fork_index = philo->env->no_philos - 1;
	else
		left_fork_index = philo->index - 2;
	if (philo->left_fork)
	{
		philo->left_fork = 0;
		pthread_mutex_lock(&philo->env->forks_mutex[left_fork_index]);
		philo->env->forks[left_fork_index] = 1;
		pthread_mutex_unlock(&philo->env->forks_mutex[left_fork_index]);
	}
}
