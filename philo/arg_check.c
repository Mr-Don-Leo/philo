/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:10:45 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 02:11:20 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void error_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int arg_check(int argc, char **argv)
{
	int index; 

	index = 2;
	argc--;
	if (argc != 5 && argc != 4)
		error_exit(ERROR_I);
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[1]) > 200)
		error_exit("Error: philosophers should be between 1 - 200.\n");
	while (index < 5)
	{
		if (ft_atoi(argv[index]) == -1)
			error_exit("Error: time should be between 1 - INT_MAX.\n");
		index++;
	}
	if (argc == 5)
	{
		if (ft_atoi(argv[5]) == -1)
			error_exit("Error: meals should be between 1 - INT_MAX.\n");
	}
	return (1);
}
