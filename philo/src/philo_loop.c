/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actionloop.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:08 by yzaim         #+#    #+#                 */
/*   Updated: 2023/09/01 16:40:54 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_check_thread_creation(t_var *data)
{
	int	check;

	pthread_mutex_lock(&data->start);
	check = data->total_philo_threads;
	pthread_mutex_unlock(&data->start);
	if (check != data->n_philos)
		return (false);
	return (true);
}

void	ft_update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->time);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->time);
}

void	*ft_action_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!ft_check_thread_creation(philo->data))
		return (NULL);
	ft_update_last_meal_time(philo);
	if (philo->philo_id % 2 == 1)
		ft_sleep_ms(philo, philo->data->time_to_eat / 2);
	while (true)
	{
		ft_take_forks(philo);
		if (!ft_eat(philo))
			break ;
		if (!ft_sleep(philo))
			break ;
		if (philo_print(philo, THINK))
			break ;
	}
	return (NULL);
}
