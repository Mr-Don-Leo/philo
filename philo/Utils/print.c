/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:30:48 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/23 16:52:16 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print(t_philo *philo, pthread_mutex_t *lock, char *str)
{
	pthread_mutex_lock(lock);
	printf("%lu %d %s\n", (get_time() - philo->env->start), philo->index, str);
	pthread_mutex_unlock(lock);
}
