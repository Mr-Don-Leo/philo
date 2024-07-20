/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:06:09 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:11:20 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_philo **philo, t_env *env)
{
	int index;

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