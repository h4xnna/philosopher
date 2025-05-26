/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:16:51 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:35:23 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_philo *philo, t_data *data, int i)
{
	int	time;
	int	last_meal;

	time = get_time();
	pthread_mutex_lock(&philo[i].meal_lock);
	last_meal = philo[i].last_meal;
	pthread_mutex_unlock(&philo[i].meal_lock);
	if (time - last_meal >= data->time_to_die)
	{
		print_status(data, philo[i].id, "died");
		stop(data);
		return (1);
	}
	return (0);
}

int	famine(t_philo *philo, t_data *data)
{
	int	i;

	while (!data->someone_died && data->must_eat)
	{
		if (all_eat(data, philo) > 0)
			stop(data);
		i = 0;
		while (i < data->philo_nb)
		{
			if (check_philosopher(philo, data, i))
				return (0);
			i++;
		}
	}
	return (1);
}

int	all_eat(t_data *data, t_philo *philo)
{
	int	eat;
	int	i;
	int	nb;

	eat = 0;
	i = 0;
	nb = data[i].philo_nb;
	if (data[0].must_eat == -2)
		return (-2);
	while (i < nb)
	{
		pthread_mutex_lock(&philo[i].meal_lock);
		if (philo[i].meals_eaten >= data->must_eat)
			eat++;
		pthread_mutex_unlock(&philo[i].meal_lock);
		i++;
	}
	if (eat == nb)
		return (1);
	return (0);
}
