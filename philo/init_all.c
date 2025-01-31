/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:55:35 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/25 11:18:08 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief Initialize forks
/// @param env 
void	init_forks(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->no_philos)
	{
		env->forks[index] = 1;
		index++;
	}
}

/// @brief Initialize mutexes
/// @param env 
void	init_mutexs(t_env *env)
{
	int	index;

	index = 0;
	pthread_mutex_init(&env->print, NULL);
	pthread_mutex_init(&env->died_mutex, NULL);
	pthread_mutex_init(&env->death_check_mutex, NULL);
	pthread_mutex_init(&env->sync_mutex, NULL);
	while (index < env->no_philos)
	{
		pthread_mutex_init(&env->forks_mutex[index], NULL);
		index++;
	}
}

/// @brief Initialize environment
/// @param argc 
/// @param argv 
/// @param env 
void	init_env(int argc, char **argv, t_env *env)
{
	env->no_philos = ft_atoi(argv[1]);
	env->ttd = ft_atoi(argv[2]);
	env->tte = ft_atoi(argv[3]);
	env->tts = ft_atoi(argv[4]);
	env->died = 0;
	env->forks = malloc(sizeof(int) * env->no_philos);
	env->no_meals = -1;
	if (!env->forks)
		error_exit("Error: malloc failed.\n");
	env->forks_mutex = malloc(sizeof(pthread_mutex_t) * env->no_philos);
	if (!env->forks_mutex)
	{
		free(env->forks);
		error_exit("Error: malloc failed.\n");
	}
	init_forks(env);
	if (argc == 6)
		env->no_meals = ft_atoi(argv[5]);
	init_mutexs(env);
	env->start = get_time();
}

/// @brief Initialize philosophers
/// @param philo 
/// @param env 
void	init_philos(t_philo **philo, t_env *env)
{
	int	index;

	index = 0;
	while (index < env->no_philos)
	{
		philo[index] = malloc(sizeof(t_philo));
		if (!philo[index])
			error_exit("Error: malloc failed.\n");
		philo[index]->index = index + 1;
		philo[index]->left_fork = 0;
		philo[index]->right_fork = 0;
		philo[index]->meals = 0;
		philo[index]->last_meal = 0;
		philo[index]->env = env;
		index++;
	}
}
