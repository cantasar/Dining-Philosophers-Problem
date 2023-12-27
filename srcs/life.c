/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:59:42 by ctasar            #+#    #+#             */
/*   Updated: 2023/12/27 15:15:23 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*lifecycle(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->lock);
	printf("%llu %d has taken a fork\n", get_time() - philo->start_time, philo->index + 1);
	pthread_mutex_unlock(philo->lock);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lock);
	printf("%llu %d has taken a fork\n", get_time() - philo->start_time, philo->index + 1);
	printf("%llu %d is eating\n", get_time() - philo->start_time, philo->index + 1);
	pthread_mutex_unlock(philo->lock);

	return (NULL);
}
