/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:32:03 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:35:14 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->data, philo->id, "has taken a fork");
		ft_usleep(1, philo->data);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->data, philo->id, "has taken a fork");
		print_status(philo->data, philo->id, "is eating");
		pthread_mutex_lock(&philo->meal_lock);
		philo->meals_eaten += 1;
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->meal_lock);
		ft_usleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
		take_fork(philo);
}

int	stop(t_data *data)
{
	pthread_mutex_lock(&data->stop);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->stop);
	return (0);
}

int	is_simulation_stopped(t_philo *philo)
{
	int	check;

	pthread_mutex_lock(&philo->data->stop);
	check = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->stop);
	return (check);
}

int	check_meal_count(t_philo *philo, t_data *data, int i)
{
	pthread_mutex_lock(&philo[i].meal_lock);
	if (philo[i].meals_eaten == data[i].must_eat)
	{
		pthread_mutex_unlock(&philo[i].meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo[i].meal_lock);
	return (0);
}

int	check_philosopher(t_philo *philo, t_data *data, int i)
{
	if (check_meal_count(philo, data, i))
		return (0);
	if (check_death(philo, data, i))
		return (1);
	if (is_simulation_stopped(philo))
		return (1);
	return (0);
}
