/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:29:40 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/06 17:54:24 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_philo_check(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	if (*philo->is_dead == 1)
		return (1);
	if (philo->num_eaten != -1 && philo->num_eaten == philo->must_eat)
	{
		pthread_mutex_unlock(philo->lock);
		return (1);
	}
	if (*philo->is_dead == 1)
		return (1);
	if ((get_time() - philo->last_eat_time) > \
		philo->time_to_die)
	{
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo->lock);
		printf("%llu %d died\n", get_time() - philo->start_time, philo->index + 1);
		return (1);
	}
	pthread_mutex_unlock(philo->lock);
	return (0);
}