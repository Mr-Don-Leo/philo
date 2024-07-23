/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:26:42 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:34:44 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// @brief Get the current time in milliseconds
/// @param void
/// @return size_t
size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error: fetching timeofday failed.\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
