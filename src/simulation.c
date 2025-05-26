/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:59:43 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:34:19 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int	famine(t_philo *philo, t_data *data)
// {
// 	int	i;
// 	int	last_meal;
// 	int	time;

// 	while (!data->someone_died && data->must_eat)
// 	{
// 		i = 0;
// 		while (i < data->philo_nb)
// 		{
// 			if (all_eat(data, philo) > 0)
// 				stop(data);
// 			pthread_mutex_lock(&philo[i].meal_lock);
// 			if (philo[i].meals_eaten == data[i].must_eat)
// 			{
// 				pthread_mutex_unlock(&philo[i].meal_lock);
// 				i++;
// 				continue ;
// 			}
// 			pthread_mutex_unlock(&philo[i].meal_lock);
// 			time = get_time();
// 			pthread_mutex_lock(&philo->meal_lock);
// 			last_meal = philo[i].last_meal;
// 			pthread_mutex_unlock(&philo->meal_lock);
// 			if (time - last_meal >= data->time_to_die)
// 			{
// 				print_status(data, philo[i].id, "died");
// 				stop(data);
// 			}
// 			if (is_simulation_stopped(philo))
// 				return (0);
// 			i++;
// 		}
// 	}
// 	return (1);
// }

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo->data, philo->id, "has taken a fork");
	if (philo->data->philo_nb == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->data, philo->id, "has taken a fork");
	print_status(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->meals_eaten += 1;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_think_sleep(t_philo *philo)
{
	if (philo->data->philo_nb == 1)
		return ;
	print_status(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	if (is_simulation_stopped(philo))
		return ;
	print_status(philo->data, philo->id, "is thinking");
	ft_usleep(1, philo->data);
}

// int	monitoring(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->stop);
// 	if (&philo->data->someone_died)
// 	{
// 		pthread_mutex_unlock(&philo->data->stop);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->stop);
// }

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_simulation_stopped(philo))
	{
		if (philo->data->must_eat == philo->meals_eaten)
			break ;
		philo_eat(philo);
		if (is_simulation_stopped(philo) || philo->data->philo_nb == 1)
			return (NULL);
		if (philo->data->must_eat == philo->meals_eaten)
			break ;
		philo_think_sleep(philo);
		if (is_simulation_stopped(philo))
			return (NULL);
	}
	return (NULL);
}
