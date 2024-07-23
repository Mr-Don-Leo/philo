/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:24:52 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:04:03 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief The sleeping function is called when the philosopher is done eating.
/// @param philo
/// @return
int	death(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->death_check_mutex);
	if ((get_time() - philo->env->start) - philo->last_meal >= philo->env->ttd)
	{
		if (value_check(philo->env->died, philo->env->died_mutex))
			return ((void)pthread_mutex_unlock(&philo->env->death_check_mutex),
				0);
		pthread_mutex_lock(&philo->env->sync_mutex);
		philo->env->died = 1;
		pthread_mutex_unlock(&philo->env->sync_mutex);
		usleep(600);
		print(philo, &philo->env->print, DEATH);
		pthread_mutex_unlock(&philo->env->death_check_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->env->death_check_mutex);
	return (1);
}

/// @brief The sleeping function is called when the philosopher is done eating.
/// @param philo
/// @return int
int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->sync_mutex);
	if (value_check(philo->env->died, philo->env->died_mutex))
		return ((void)pthread_mutex_unlock(&philo->env->sync_mutex), 0);
	pthread_mutex_unlock(&philo->env->sync_mutex);
	print(philo, &philo->env->print, SLEEPING);
	leave_forks(philo);
	if (!my_usleep(philo->env->tts, philo))
		return (0);
	return (1);
}

/// @brief The thinking function is called when the philosopher is 
///			done sleeping.
/// @param philo
/// @return int
int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->sync_mutex);
	if (value_check(philo->env->died, philo->env->died_mutex))
		return ((void)pthread_mutex_unlock(&philo->env->sync_mutex), 0);
	pthread_mutex_unlock(&philo->env->sync_mutex);
	print(philo, &philo->env->print, THINKING);
	return (1);
}

/// @brief The eating function is called when the philosopher is ready to eat.
/// @param philo
/// @return int
int	eating(t_philo *philo)
{
	while (!take_forks(philo))
	{
		usleep(100);
		if (!death(philo))
			return (0);
	}
	philo->last_meal = (get_time() - philo->env->start);
	pthread_mutex_lock(&philo->env->sync_mutex);
	if (value_check(philo->env->died, philo->env->died_mutex))
		return ((void)pthread_mutex_unlock(&philo->env->sync_mutex), 0);
	pthread_mutex_unlock(&philo->env->sync_mutex);
	print(philo, &philo->env->print, EATING);
	if (!my_usleep(philo->env->tte, philo))
		return (0);
	philo->meals++;
	return (1);
}

/// @brief The process function is the main function that the threads
///         will run when created.
/// @param philosopher
/// @return void*
void	*process(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	while (1)
	{
		pthread_mutex_lock(&philo->env->sync_mutex);
		if (philo->env->died && philo->meals == philo->env->no_meals)
		{
			pthread_mutex_unlock(&philo->env->sync_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->env->sync_mutex);
		if (philo->index % 2 != 0 && philo->meals == 0)
		{
			if (!my_usleep(philo->env->tte / 2, philo))
				return (leave_forks(philo), NULL);
		}
		if (!eating(philo) || philo->meals == philo->env->no_meals
			|| !sleeping(philo) || !thinking(philo))
			return (leave_forks(philo), NULL);
	}
	return (leave_forks(philo), NULL);
}
