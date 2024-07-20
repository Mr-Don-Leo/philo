/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:21:21 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:22:58 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void thread_create(t_philo **philo, t_env *env)
{
	int index;

	index = 0;
	while (index < env->no_philos)
	{
		pthread_create(&philo[index]->philosopher, NULL, process, philo[index]);
		index++;
	}
}

