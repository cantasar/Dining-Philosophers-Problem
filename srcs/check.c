/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:29:40 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/15 15:46:40 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	must_eat_check(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo->lock);
	while (i < philo->number_philo)
	{
		if (philo[i].must_eat > 0)
		{
			pthread_mutex_unlock(philo->lock);
			return (0);
		}
		i++;
	}
	return (1);
}

int	dead_check(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo->lock);
	while (i < philo->number_philo)
	{
		if (philo[i].is_dead == 1)
		{
			usleep(100);
			printf("%llu %d died\n", get_time() - philo->start_time, i + 1);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(philo->lock);
	return (0);
}
