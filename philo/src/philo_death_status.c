/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_death_status.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:08 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 17:28:16 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_check_live_philo(t_philo *philo)
{
	int		i;
	bool	alive;

	i = 0;
	while (i < philo->data->n_philos)
	{
		pthread_mutex_lock(&philo->data->alive_philo_mutex[i]);
		alive = philo->data->alive_philos[i];
		pthread_mutex_unlock(&philo->data->alive_philo_mutex[i]);
		if (alive == 0)
			return (true);
		i++;
	}
	return (false);
}

bool	ft_death_status(t_philo *philo)
{
	bool	death;

	pthread_mutex_lock(&philo->data->death);
	death = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->death);
	return (death);
}

