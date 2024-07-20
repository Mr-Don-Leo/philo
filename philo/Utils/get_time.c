/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:26:42 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:03:40 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error: gettimeofday failed.\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}