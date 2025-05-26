/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:36:49 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 16:43:30 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (!philo)
		return (NULL);
	if (init_mutexes(data))
		return (free(philo), NULL);
	while (i < data->philo_nb)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = data->start_time;
		philo[i].left_fork = &data->forks[i];
		if ((i + 1) == data->philo_nb)
			philo[i].right_fork = philo[0].left_fork;
		else
			philo[i].right_fork = &data->forks[i + 1];
		philo[i].data = data;
		if (pthread_mutex_init(&philo[i].meal_lock, NULL) != 0)
			return (free(philo), free(data->forks), NULL);
		i++;
	}
	return (philo);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_nb));
	if (!data->forks)
		return (1);
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&(data)->forks[i], NULL) != 0)
			return (free(data->forks), 1);
		i++;
	}
	if (pthread_mutex_init(&(data)->print_mutex, NULL) != 0)
		return (free(data->forks), 1);
	if (pthread_mutex_init(&data->stop, NULL) != 0)
		return (free(data->forks), 1);
	return (0);
}

void	print_status(t_data *data, int id, char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->stop);
	if (!data->someone_died)
	{
		timestamp = get_time() - data->start_time;
		printf("%lld %d %s\n", timestamp, id, status);
	}
	pthread_mutex_unlock(&data->stop);
	pthread_mutex_unlock(&data->print_mutex);
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nb)
	{
		pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]);
		i++;
	}
}
