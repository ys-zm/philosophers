/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:08 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 18:47:21 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	philo_print(philo, TAKE_FORK);
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, TAKE_FORK);
	return (true);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

t_status	check_death(t_philo *philo)
{
	long	diff;

	pthread_mutex_lock(&philo->data->time);
	diff = get_time_ms() - philo->last_meal;
	pthread_mutex_unlock(&philo->data->time);
	if ((int)diff > philo->data->time_to_die)
		return (DEAD);
	return (ALIVE);
}

bool	ft_eat(t_philo *philo)
{
	if (!philo_print(philo, EAT))
	{
		ft_update_last_meal_time(philo);
		ft_sleep_ms(philo, philo->data->time_to_eat);
		ft_drop_forks(philo);
		// if (ft_update_meal_count(philo))
		// 	return (false);
		philo->meal_count++;
		if (philo->meal_count == philo->data->n_meals)
			return (false);
		return (true);
	}
	ft_drop_forks(philo);
	return (false);
}

bool	ft_sleep(t_philo *philo)
{
	if (!philo_print(philo, SLEEP))
	{
		ft_sleep_ms(philo, philo->data->time_to_sleep);
		return (true);
	}
	return (false);
}
