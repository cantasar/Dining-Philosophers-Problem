/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:22:15 by ctasar            #+#    #+#             */
/*   Updated: 2023/12/24 18:45:59 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dead;
	t_philo			*philo;

	if (check_args(argc, argv) != 1)
	{
		printf("Invalid Argumans!\n");
		printf("./philo number_of_philo time_to_die time_to_eat time_to_sleep must_eat\n");
		return (1);
	}
	philo = malloc(sizeof(*philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	dead = malloc(sizeof(pthread_mutex_t));
	init_args(argc, argv, philo);
	init_mutex(philo, argv, forks, dead);
	
	return 0;
}
