/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:55:35 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:20:45 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_forks(t_env *env)
{
	int index;

	index = 0;
	while (index < env->no_philos)
	{
		env->forks[index] = 1;
		index++;
	}
}

void init_mutexs(t_env *env)
{
	int index;

	index = 0;
	pthread_mutex_init(&env->print, NULL);
	pthread_mutex_init(&env->died_mutex, NULL);
	pthread_mutex_init(&env->death_check_mutex, NULL);
	pthread_mutex_init(&env->meal_check_mutex, NULL);
	while (index < env->no_philos)
	{
		pthread_mutex_init(&env->forks_mutex[index], NULL);
		index++;
	}
}

void init_env(int argc, char **argv, t_env *env)
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
