/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:32:11 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:19:52 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_all_philos(t_philo **philo, t_env *env)
{
	int i;

	i = 0;
	while (i < env->no_philos)
	{
		printf("philo[%d]:\n  index: %d\n  left_fork: %d\n  right_fork: %d\n  meals: %d\n  last_meal: %d\n  env: %p\n",
			i, philo[i]->index, philo[i]->left_fork, philo[i]->right_fork, philo[i]->meals, philo[i]->last_meal, philo[i]->env);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_philo **philo;
	t_env	env;
	
	if (arg_check(argc, argv))
	{
		printf("-- passed arg check --\n");
		printf("  OK!\n");
		init_env(argc, argv, &env);
		printf("-- passed init env --\n");
		philo = malloc(sizeof(t_philo *) * env.no_philos);
		if (!philo)
			error_exit("Error: malloc failed.\n");
		printf("  env.no_philos: %d\n  env.ttd: %d\n  env.tte: %d\n  env.tts: %d\n", env.no_philos, env.ttd, env.tte, env.tts);
		printf("  env.no_meals: %d\n  env.start: %zu\n", env.no_meals, env.start);
		init_philos(philo, &env);
		printf("-- passed init philos --\n");
		// print_all_philos(philo, &env);
		thread_create(philo, &env);
	}
	return (-1);
}
