/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_simulation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:15:00 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/24 18:15:05 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_create_threads(t_philo *philos)
{
	int	n_philos;
	int	i;

	n_philos = philos->data->n_philos;
	pthread_mutex_lock(&philos->data->philo_thread_mutex);
	i = 0;
	philos->data->total_philo_threads = 0;
	philos->data->is_dead = false;
	while (i < n_philos)
	{
		if (pthread_create(&philos[i].philo_thread, NULL, ft_action_loop, &philos[i]))
			break ;
		philos->data->total_philo_threads += 1;
		i++;
	}
	ft_set_start_time(philos->data, philos);
	pthread_mutex_unlock(&philos->data->philo_thread_mutex);
	if (philos->data->total_philo_threads != n_philos)
		return (false);
	return (true);
}

bool	ft_join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->total_philo_threads)
	{
		if (pthread_join(philos[i].philo_thread, NULL))
			return (false);
		i++;
	}
	return (true);
}

void	philo_simulation(t_philo *philos)
{
	if (philos->data->n_philos == 1)
	{
		ft_set_start_time(philos->data, philos);
		single_philo_death(philos, philos->data->time_to_die);
		return ;
	}
	if (!ft_create_threads(philos))
	{
		ft_join_threads(philos);
		ft_destroy_all_mutexes(philos);
		ft_free_philos(philos);
		printf("Error creating threads\n");
		return ;
	}
	philo_check_status(philos);
	if (!ft_join_threads(philos))
		printf("Error joining threads\n");
}
