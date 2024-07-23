/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:55 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:34:28 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// @brief Ascii to integer conversion
/// @param string 
/// @return int
int	ft_atoi(char *string)
{
	unsigned long long	total;

	total = 0;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			return (-1);
		string++;
	}
	while (*string && (*string) >= '0' && (*string) <= '9')
	{
		total = (total * 10) + (*string - '0');
		if (total > INT_MAX)
			return (-1);
		string++;
	}
	if (*string)
		return (-1);
	return (total);
}
