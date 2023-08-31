/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_death.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:17 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 17:29:51 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	check_philos_done_eating(t_philo *philo)
// {
// 	int	n_meals;

// 	n_meals = philo->data->n_meals;
// 	pthread_mutex_lock(&philo->meal_count_mutex);
// 	if (n_meals != INFINITE && philo->full == true)
// 	{
// 		pthread_mutex_unlock(&philo->meal_count_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->meal_count_mutex);
// 	return (0);
// }

void	ft_death(t_philo *philo)
{
	long	now;

	now = find_time_diff(get_time_ms(), philo->data->start_time);
	pthread_mutex_lock(&philo->data->death);
	philo->data->is_dead = true;
	printf("%ld: philo %d died\n", now, philo->philo_id);
	pthread_mutex_unlock(&philo->data->death);
}

// static void	ft_full(t_var *data)
// {
// 	pthread_mutex_lock(&data->death);
// 	data->is_dead = true;
// 	pthread_mutex_unlock(&data->death);
// }

size_t	ft_time_since_meal(t_philo *philos, int philo_index)
{
	long	time_since_meal;
	
	pthread_mutex_lock(&philos[philo_index].data->time);
	time_since_meal = get_time_ms() - philos[philo_index].last_meal;
	pthread_mutex_unlock(&philos[philo_index].data->time);
	return (time_since_meal);
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
			// philos_done_eating += check_philos_done_eating(&philos[i]);
			time_since_meal = ft_time_since_meal(philos, i);
			if (time_since_meal > (size_t)philos->data->time_to_die)
				return (ft_death(&philos[i]));
			i++;
		}
		// if (philos_done_eating == n_philos)
		// 	return (ft_full(philos->data));
	}
}
