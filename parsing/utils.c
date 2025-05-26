/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:42:05 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:34:09 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long long time, t_data *data)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	current_time = start_time;
	while (current_time - start_time < time)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->stop);
		if (data->someone_died == 1)
		{
			pthread_mutex_unlock(&data->stop);
			return ;
		}
		pthread_mutex_unlock(&data->stop);
		if (current_time - start_time > 150)
			usleep(150);
		else
			usleep(current_time - start_time);
	}
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->philo_nb)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philo[i].meal_lock);
			i++;
		}
	}
	pthread_mutex_destroy(&data->print_mutex);
}

void	free_all(t_data *data)
{
	destroy_mutexes(data);
	pthread_mutex_destroy(&data->stop);
	if (data->philo)
	{
		if (data->forks)
			free(data->forks);
		free(data->philo);
	}
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		seconds;
	long long		microsecondes;
	long long		miliseconds;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	seconds = tv.tv_sec;
	microsecondes = tv.tv_usec;
	miliseconds = (seconds * 1000) + (microsecondes / 1000);
	return (miliseconds);
}
