/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:24:52 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:42:17 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *process(void *philosopher)
{
	t_philo *philo;

	philo = philosopher;
	pthread_mutex_lock(&philo->env->sync_mutex);
	while (!philo->env->died
		&& (philo->meals != philo->env->no_meals))
	{
		pthread_mutex_unlock(&philo->env->sync_mutex);
		if (philo->index % 2 == 0 )
			d_fork();
		if (eat(philo))
			return (d_fork(), NULL);
	}
}
