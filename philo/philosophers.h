/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:44 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/21 03:04:03 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR_I	"Usage: ./philo [philos] [time_to_die] [time_to_eat] \
[time_to_sleep] **[meals_required]\n"
# define DEATH		"died"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define FORK		"has taken a fork"

// ttd: time to die, tte: time to eat, tts: time to sleep
typedef struct s_env
{
	int			no_philos;
	int			ttd;
	int			tte;
	int			tts;
	
	int			died;
	int			*forks;
	int			no_meals;
	size_t		start;
	pthread_mutex_t *forks_mutex;
	pthread_mutex_t print;
	pthread_mutex_t died_mutex;
	pthread_mutex_t death_check_mutex;
	pthread_mutex_t sync_mutex;
}			t_env;

typedef struct s_philo
{
	int			index;
	int			left_fork;
	int			right_fork;
	int			meals;
	int			last_meal;
	t_env		*env;
	pthread_t 	philosopher;
}			t_philo;

/*
** parsing
*/

int		arg_check(int argc, char **argv);
int		ft_atoi(char *str);
void	error_exit(char *str);
void	init_env(int argc, char **argv, t_env *env);
void	init_philos(t_philo **philo, t_env *env);
size_t	get_time(void);
void	thread_create(t_philo **philo, t_env *env);
void	*process(void *philosopher);


#endif
