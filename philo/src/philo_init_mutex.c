/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_init_mutex.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:44 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 14:20:52 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philo_mutexes(t_philo *philos)
{
	int		i;
	int		n_philos;
	t_philo	*philo;

	i = 0;
	n_philos = philos->data->n_philos;
	while (i < n_philos)
	{
		philo = &philos[i];
		if (pthread_mutex_init(&philo->r_fork, NULL))
			return (ft_error(MUTEX_ERR), false);
		if (pthread_mutex_init(&philo->meal_count_mutex, NULL))
			return (ft_error(MUTEX_ERR), false);
		// if (pthread_mutex_init(&philo->time_last_meal_mutex, NULL))
		// 	return (ft_error(MUTEX_ERR), false);
		i++;
	}
	set_l_fork(philos, n_philos);
	return (true);
}

bool	init_data_mutexes(t_philo *philos)
{
	if (pthread_mutex_init(&philos->data->start, NULL))
		return (false);
	if (pthread_mutex_init(&philos->data->death, NULL))
	{
		pthread_mutex_destroy(&philos->data->start);
		return (false);
	}
	if (pthread_mutex_init(&philos->data->time, NULL))
	{
		pthread_mutex_destroy(&philos->data->start);
		pthread_mutex_destroy(&philos->data->death);
		return (false);
	}
	// if (pthread_mutex_init(&philos->data->print_mutex, NULL))
	// {
	// 	pthread_mutex_destroy(&philos->data->start);
	// 	pthread_mutex_destroy(&philos->data->death);
	// 	return (false);
	// }
	return (true);
}

bool	init_all_mutexes(t_philo *philos)
{
	if (!init_data_mutexes(philos))
		return (false);
	if (!init_philo_mutexes(philos))
	{
		ft_destroy_all_mutexes(philos);
		return (false);
	}
	return (true);
}
