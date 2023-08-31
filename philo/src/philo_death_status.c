/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_death_status.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:08 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 15:19:52 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_death_status(t_philo *philo)
{
	bool	death;

	pthread_mutex_lock(&philo->data->death);
	death = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->death);
	return (death);
}

