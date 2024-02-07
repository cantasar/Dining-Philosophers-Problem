/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:22:33 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/07 18:31:03 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					return (0);
				if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) == 0)
					return (0);
				j++;
			}
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	init_args(int argc, char **argv, t_philo *philo)
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].index = i;
		philo[i].number_philo = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atoi(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].start_time = get_time();
		philo[i].last_eat_time = get_time();
		philo[i].is_dead = &dead;
		i++;
	}
}

void	init_forks(t_philo *philo, pthread_mutex_t *forks, \
					pthread_mutex_t *lock)
{
	int	i;

	i = 0;
	while (i < philo->number_philo)
	{
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % philo->number_philo];
		pthread_mutex_init(philo[i].left_fork, NULL);
		pthread_mutex_init(philo[i].right_fork, NULL);
		philo[i].lock = lock;
		i++;
	}
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_philo)
	{
		pthread_create(&philo[i].thread, NULL, &lifecycle, &philo[i]);
		i++;
		usleep(100);
	}
	while (1)
	{
		if (ft_philo_check(philo))
			break ;
	}
	i = 0;
	while (i < philo->number_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
