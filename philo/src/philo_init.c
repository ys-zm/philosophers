/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:44 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 14:58:49 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_l_fork(t_philo *philos, int n_philos)
{
	int	i;

	i = 1;
	while (i < n_philos)
	{
		philos[i].l_fork = &philos[i - 1].r_fork;
		i++;
	}
	philos[0].l_fork = &philos[i - 1].r_fork;
}

bool	init_philo(t_var *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		philos[i].philo_id = i + 1;
		philos[i].data = data;
		philos[i].meal_count = 0;
		philos[i].full = false;
		i++;
	}
	data->is_dead = false;
	return (true);
}

bool	ft_init(t_var *data, t_philo *philos)
{
	if (!init_philo(data, philos))
		return (false);
	if (!init_all_mutexes(philos))
		return (false);
	return (true);
}
