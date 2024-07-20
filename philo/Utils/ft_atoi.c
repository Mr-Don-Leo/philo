/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:55 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/18 14:48:20 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(char *nptr)
{
	unsigned long long	res;

	res = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			return (-1);
		nptr++;
	}
	while (*nptr && (*nptr) >= '0' && (*nptr) <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		if (res > INT_MAX)
			return (-1);
		nptr++;
	}
	if (*nptr)
		return (-1);
	return (res);
}