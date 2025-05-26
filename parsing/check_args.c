/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 07:34:20 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:31:06 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_number_args(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (print_error(" : numbers args"), 0);
	while (++i < ac)
	{
		if (str_is_digit(av[i]) == 0)
			return (print_error(" : only digit args"), 0);
	}
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -2;
	data->someone_died = 0;
	data->start_time = get_time();
	if (data->philo_nb <= 0 || data->philo_nb > 200 || data->time_to_die <= 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0 || (ac == 6
			&& data->must_eat <= 0))
		return (print_error(": args false\n"), 0);
	return (1);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + (str[i] - '0');
		++i;
		if (num > INT_MAX)
			break ;
	}
	return (num * sign);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

// int	main(int ac, char **av)
// {
// 	t_data	data;
// 	int		i;
// 	t_philo	*philos;

// 	philos = NULL;

// 	if (!check_number_args(ac, av, &data))
// 		return(0);
// 	else
// 	{
// 		i = 0;
// 		philos = init_philo(&data);
// 		data.philo = philos;
// 		// while (i < data.philo_nb)
// 		// {
// 		// 	printf("Philosopher %d:\n", philos[i].id);
// 		// 	printf("  -Meals Eaten: %d\n", philos[i].meals_eaten);
// 		// 	printf("  -Last Meal: %d\n", philos[i].last_meal);
// 		// 	printf("  -Left Fork: %p\n", philos[i].left_fork);
// 		// 	printf("  -Right Fork: %p\n", philos[i].right_fork);
// 		// 	i++;
// 		// }
// 		init_thread(philos);
// 		// philo_routine(philos);
// 	}
// 	i = 0;
// 	while (i < philos->data->philo_nb)
// 	{
// 		pthread_join(philos[i].thread, NULL);
// 		i++;
// 	}
// 	// free(philos);
// 	free_all(&data);
// 	final_print(&data);
// }
