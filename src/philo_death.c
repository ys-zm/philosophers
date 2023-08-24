/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_death.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:17 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/24 18:14:19 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philos_done_eating(t_philo *philo)
{
	int	n_meals;

	n_meals = philo->data->n_meals;
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (n_meals != INFINITE && philo->full == true)
	{
		pthread_mutex_unlock(&philo->meal_count_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_count_mutex);
	return (0);
}

void	ft_death(t_philo *philo)
{
	long	now;

	now = find_time_diff(get_time_ms(), philo->start_time_ms);
	pthread_mutex_lock(&philo->data->death);
	philo->data->is_dead = true;
	printf("%ld: philo %d died\n", now, philo->philo_id);
	pthread_mutex_unlock(&philo->data->death);
}

static void	ft_full(t_var *data)
{
	pthread_mutex_lock(&data->death);
	data->is_dead = true;
	pthread_mutex_unlock(&data->death);
}

void	philo_check_status(t_philo *philos)
{
	int	i;
	int	n_philos;
	int	philos_done_eating;

	n_philos = philos->data->n_philos;
	while (1)
	{
		i = 0;
		philos_done_eating = 0;
		while (i < n_philos)
		{
			philos_done_eating += check_philos_done_eating(&philos[i]);
			pthread_mutex_lock(&philos[i].time_last_meal_mutex);
			if (philos[i].status == DEAD)
			{
				pthread_mutex_unlock(&philos[i].time_last_meal_mutex);
				return (ft_death(&philos[i]));
			}
			pthread_mutex_unlock(&philos[i].time_last_meal_mutex);
			i++;
		}
		if (philos_done_eating == n_philos)
			return (ft_full(philos->data));
		usleep(100);
	}
}
