/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:39:45 by ctasar            #+#    #+#             */
/*   Updated: 2024/01/03 19:48:07 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				index;
	int				number_philo;
	t_time			time_to_die;
	t_time			time_to_sleep;
	t_time			time_to_eat;
	int				must_eat;

	t_time			start_time;
	t_time			last_eat_time;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;

}	t_philo;

//init 
int		check_args(int argc, char **argv);
void	init_args(int argc, char **argv, t_philo *philo);
void	init_forks(t_philo *philo, pthread_mutex_t *forks);
void	create_threads(t_philo *philo);

//utils
int		ft_atoi(char *str);
t_time	get_time(void);

//life
void	*lifecycle(void *arg_philo);

#endif