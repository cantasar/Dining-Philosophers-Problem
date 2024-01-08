/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:59:42 by ctasar            #+#    #+#             */
/*   Updated: 2024/01/03 20:21:41 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*lifecycle(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	printf("thread p%d started at %llu\n", philo->index + 1, get_time());
	// pthread_mutex_lock(philo->left_fork);
	// printf("%llu %d has taken a fork\n", get_time() - philo->start_time, philo->index + 1);
	// pthread_mutex_lock(philo->right_fork);
	// printf("%llu %d has taken a fork\n", get_time() - philo->start_time, philo->index + 1);
	// printf("%llu %d is eating\n", get_time() - philo->start_time, philo->index + 1);
	// pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_unlock(philo->left_fork);

	printf("index %d\n", philo->index);
	printf("start_time %llu\n", philo->start_time);
	printf("last_eat_time %llu\n", philo->last_eat_time);

	printf("number_philo %d\n", philo->number_philo);
	printf("time_to_die %llu\n", philo->time_to_die);
	printf("time_to_sleep %llu\n", philo->time_to_sleep);
	printf("time_to_eat %llu\n", philo->time_to_eat);
	printf("must_eat %d\n", philo->must_eat);

	printf("thread p%d closed\n", philo->index + 1);
	printf("\n");
	printf("\n");
	usleep(100);

	return (NULL);
}
