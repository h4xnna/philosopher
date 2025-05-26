/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:05:59 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:34:37 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	philos = NULL;
	if (!check_number_args(ac, av, &data))
		return (0);
	else
	{
		philos = init_philo(&data);
		if (!philos)
			return (1);
		data.philo = philos;
		init_thread(philos);
	}
	i = 0;
	famine(philos, &data);
	while (i < philos->data->philo_nb)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	free_all(&data);
	final_print(&data);
}
