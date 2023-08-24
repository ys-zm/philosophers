/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:14:52 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/24 18:14:53 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_input_check(char **argv, t_var *data)
{
	if (!*argv[1] || !*argv[2] || !*argv[3] || !*argv[4])
		return (false);
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_meals = ft_atoi(argv[5]);
	else
		data->n_meals = INFINITE;
	if (data->n_philos < 0 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (false);
	if (argv[5] && data->n_meals < 0)
		return (false);
	return (true);
}
