/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:22:51 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/23 16:52:24 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	value_check(int value, pthread_mutex_t lock)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&lock);
	if (value == 1)
		status = 1;
	pthread_mutex_unlock(&lock);
	return (status);
}
