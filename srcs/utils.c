/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:36:57 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/07 19:03:53 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

	num = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

t_time	get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_sleep(int wait_time, t_philo	*philo)
{
	t_time	time;

	time = get_time();
	while (get_time() - time < (t_time)wait_time)
	{
		if (ft_philo_check(philo))
			return ;
		usleep(100);
	}
	return ;
}
