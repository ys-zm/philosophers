/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:34 by yzaim         #+#    #+#                 */
/*   Updated: 2023/09/01 16:56:01 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philos(t_philo *philos)
{
	free(philos->data);
	free(philos);
}

void	ft_destroy_all_mutexes(t_philo *philos)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = philos->data->n_philos;
	while (++i < philos->data->init_fork_mutex)
		pthread_mutex_destroy(&philos[i].r_fork);
	i = -1;
	while (++i < philos->data->init_full_mutex)
		pthread_mutex_destroy(&philos[i].full_mutex);
	i = -1;
	while (++i < philos->data->init_life_mutex)
		pthread_mutex_destroy(&philos[i].life_mutex);
	pthread_mutex_destroy(&philos->data->time);
	pthread_mutex_destroy(&philos->data->start);
}
