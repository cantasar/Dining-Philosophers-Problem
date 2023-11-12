#include "../philosophers.h"

int check_args(int argc, char **argv)
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
				if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) == 0)
					return (0);
				j++;
			}
			i++;
		}
	}else
		return(0);
	return (1);
}

void	init_mutex(t_philo *philo, char **argv)
{
	pthread_mutex_init(&philo->left_fork, NULL);
	pthread_mutex_init(&philo->right_fork, NULL);
}

void	init_args(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		philo[i].id = i;
		philo[i].number_philo = ft_atol(argv[1]);
		philo[i].time_to_die = ft_atol(argv[2]);
		philo[i].time_to_eat = ft_atol(argv[3]);
		philo[i].time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			philo[i].eat_time = ft_atol(argv[5]);
		i++;
	}
}
