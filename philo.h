/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:03 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 17:30:24 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\033[1;31m"
# define RESET "\033[0m"

# include "printf/ft_printf.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// struct donnee partages
typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_nb;
	int				must_eat;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop;
	int				someone_died;
	struct s_philo	*philo;
}					t_data;

// strucutre philo
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				last_meal;
	pthread_mutex_t	meal_lock;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;

}					t_philo;

// parsing ../check_args
int					check_number_args(int ac, char **av, t_data *data);
int					str_is_digit(char *str);
long				ft_atoi(const char *str);

// parsing ../print_Error
void				print_error(const char *msg);
void				final_print(t_data *data);

// parsing ../utils
long long			get_time(void);
void				ft_usleep(long long time, t_data *data);
void				free_all(t_data *data);
void				destroy_mutexes(t_data *data);

// philo ../simulation
int					famine(t_philo *philo, t_data *data);
void				philo_think_sleep(t_philo *philo);
void				philo_eat(t_philo *philo);
void				*philo_routine(void *arg);
void				take_fork(t_philo *philo);

// philo ../init
int					init_mutexes(t_data *data);
void				init_thread(t_philo *philo);
t_philo				*init_philo(t_data *data);
void				print_status(t_data *data, int id, char *status);
// void				monitoring(t_philo *philo, t_data *data);

// philo ../routine_utils
int					is_simulation_stopped(t_philo *philo);
int					stop(t_data *data);
int					check_meal_count(t_philo *philo, t_data *data, int i);
void				philo_eat(t_philo *philo);
int					check_philosopher(t_philo *philo, t_data *data, int i);

// philo ../routine_utils2
int					check_death(t_philo *philo, t_data *data, int i);
int					famine(t_philo *philo, t_data *data);
int					all_eat(t_data *data, t_philo *philo);

#endif