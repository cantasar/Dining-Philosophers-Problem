/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:22:15 by ctasar            #+#    #+#             */
/*   Updated: 2024/02/06 14:11:24 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;

	if (check_args(argc, argv) != 1)
	{
		printf("Invalid Argumans!\n");
		printf("./philo number_of_philo time_to_die time_to_eat \
		time_to_sleep must_eat\n");
		return (1);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	//lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&lock, NULL);
	init_args(argc, argv, philo);
	init_forks(philo, forks, &lock);
	create_threads(philo);
	while (1)
	// {
	// 	pthread_mutex_lock(&lock);
	// 	if (!ft_philo_check(philo))
	// 	{
	// 		pthread_mutex_unlock(&lock);
	// 	}else
	// 		exit(0);
		
	// }
	
	printf("Main closed\n");
	return (0);
}
