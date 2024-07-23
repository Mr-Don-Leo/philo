/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:44 by mbabayan          #+#    #+#             */
/*   Updated: 2024/07/24 01:06:18 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
	int				no_philos;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	int				died;
	int				*forks;
	int				no_meals;
	size_t			start;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	death_check_mutex;
	pthread_mutex_t	sync_mutex;
}			t_env;

typedef struct s_philo
{
	int			index;
	int			left_fork;
	int			right_fork;
	int			meals;
	size_t		last_meal;
	t_env		*env;
	pthread_t	philosopher;
}			t_philo;

/*
** parsing
*/

int		arg_check(int argc, char **argv);
int		ft_atoi(char *string);
void	error_exit(char *str);
void	init_env(int argc, char **argv, t_env *env);
void	init_philos(t_philo **philo, t_env *env);
size_t	get_time(void);
void	thread_create(t_philo **philo, t_env *env);
void	*process(void *philosopher);
void	print(t_philo *philo, pthread_mutex_t *lock, char *str);
int		value_check(int value, pthread_mutex_t lock);
void	leave_forks(t_philo *philo);
int		take_forks(t_philo *philo);
void	thread_join(t_philo **philo, t_env *env);
int		my_usleep(size_t milliseconds, t_philo *philo);
int		death(t_philo *philo);

#endif
