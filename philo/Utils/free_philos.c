/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:15:36 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/30 14:38:21 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// @brief Free allocated memory for philosophers
/// @param philo
/// @param env
void	free_philos(t_philo **philo, t_env *env)
{
	int	index;

	index = 0;
	while (index < env->no_philos)
	{
		free(philo[index]);
		index++;
	}
	free(philo);
}
