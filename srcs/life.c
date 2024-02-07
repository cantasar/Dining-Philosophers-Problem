/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:59:42 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/07 00:23:30 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat(t_philo	*philo)
{
	if (ft_philo_check(philo))
		return;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	printf("%llu %d has taken a fork\n", get_time() - philo->start_time, \
			philo->index + 1);
	printf("%llu %d has taken a fork\n", get_time() - philo->start_time, \
			philo->index + 1);
	printf("%llu %d is eating\n", get_time() - philo->start_time, \
			philo->index + 1);
	pthread_mutex_lock(philo->lock);
	philo->last_eat_time = get_time();
	philo->num_eaten++;
	pthread_mutex_unlock(philo->lock);
	ft_sleep(200, philo);
	if (ft_philo_check(philo))
		return;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("%llu %d is sleeping\n", get_time() - philo->start_time, \
			philo->index + 1);
	ft_sleep(philo->time_to_sleep, philo);
	if (!ft_philo_check(philo))
		printf("%llu %d is thinking\n", get_time() - philo->start_time, \
				philo->index + 1);
}

void	*lifecycle(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	int i = 0;
	while (i < 20)
	{
		eat(philo);
		i++;
	}

	return (NULL);
}
