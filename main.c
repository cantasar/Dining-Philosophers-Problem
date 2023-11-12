#include "philosophers.h"

int main(int argc, char **argv)
{
	t_philo *philo;
	if (check_args(argc, argv) != 1)
	{
		printf("Invalid Argumans!\n");
		printf("./philo number_of_philo time_to_die time_to_eat time_to_sleep must_eat\n");
		return (1);
	}
	philo = malloc(sizeof(*philo) * ft_atol(argv[1]));
	init_args(argc, argv, philo);
	init_mutex(philo, argv);
	
	return 0;
}
