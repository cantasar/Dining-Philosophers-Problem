#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int 	id;

	int		number_philo;
	t_time	time_to_die;
	t_time	time_to_sleep;
	t_time	time_to_eat;
	int		eat_time;

	pthread_t	thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	//pthread_mutex_t	dead;

}	t_philo;

//init 
int 	check_args(int argc, char **argv);
void	init_args(int argc, char **argv, t_philo *philo);
void	init_mutex(t_philo *philo, char **argv);

//utils
long	ft_atol(const char *str);

#endif