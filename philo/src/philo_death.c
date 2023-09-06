/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_death.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:17 by yzaim         #+#    #+#                 */
/*   Updated: 2023/09/06 12:57:54 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_death(t_philo *philo)
{
	long	now;
	bool	full;

	pthread_mutex_lock(&philo->full_mutex);
	full = philo->full;
	pthread_mutex_unlock(&philo->full_mutex);
	if (full)
		return ;
	now = find_time_diff(get_time_ms(), philo->data->start_time);
	usleep(2500);
	printf("%ld: philo %d died\n", now, philo->philo_id);
}

size_t	ft_time_since_meal(t_philo *philos, int philo_index)
{
	long	time_since_meal;

	pthread_mutex_lock(&philos[philo_index].data->time);
	time_since_meal = get_time_ms() - philos[philo_index].last_meal;
	pthread_mutex_unlock(&philos[philo_index].data->time);
	return (time_since_meal);
}

void	ft_set_death(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->n_philos)
	{
		pthread_mutex_lock(&philos[i].life_mutex);
		philos[i].alive = false;
		pthread_mutex_unlock(&philos[i].life_mutex);
	}
}

void	philo_check_status(t_philo *philos)
{
	int		i;
	int		n_philos;
	int		philos_done_eating;
	size_t	time_since_meal;

	n_philos = philos->data->n_philos;
	ft_sleep_ms(philos, philos->data->time_to_die - 10);
	while (1)
	{
		i = 0;
		philos_done_eating = 0;
		while (i < n_philos)
		{
			time_since_meal = ft_time_since_meal(philos, i);
			if (time_since_meal > (size_t)philos->data->time_to_die)
			{
				ft_set_death(philos);
				return (ft_death(&philos[i]));
			}
			i++;
		}
	}
}
