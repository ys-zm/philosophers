/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:34 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 17:20:34 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philos(t_philo *philos)
{
	ft_destroy_all_mutexes(philos);
	free(philos->data);
	free(philos);
}

void	ft_destroy_all_mutexes(t_philo *philos)
{
	int	i;
	int	n_philos;

	i = 0;
	n_philos = philos->data->n_philos;
	while (i < n_philos)
	{
		pthread_mutex_destroy(&philos[i].meal_count_mutex);
		pthread_mutex_destroy(&philos[i].r_fork);
		pthread_mutex_destroy(&philos->data->alive_philo_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&philos->data->time);
	pthread_mutex_destroy(&philos->data->start);
	pthread_mutex_destroy(&philos->data->death);
}
