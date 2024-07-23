/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:04:44 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:35:09 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// @brief Sleep for a given amount of time, checking for death
/// @param milliseconds 
/// @param philo 
/// @return int
int	my_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start_time;
	size_t	end_time;

	start_time = get_time();
	end_time = start_time + milliseconds;
	while (get_time() < end_time)
	{
		if (!death(philo))
			return (0);
		usleep(100);
	}
	return (1);
}
