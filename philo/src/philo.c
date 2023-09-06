/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:13:59 by yzaim         #+#    #+#                 */
/*   Updated: 2023/09/01 16:50:49 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*data;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (ft_error(ARG_ERR));
	data = malloc(sizeof(t_var) * 1);
	if (!data)
		return (ft_error(MEM_ERR));
	if (!philo_input_check(argv, data))
		return (free(data), ft_error(INPUT_ERR));
	if (data->n_philos < MIN_PHILO || data->n_philos > MAX_PHILO)
		return (free(data), ft_error(N_PHILO_ERR));
	philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!philos)
		return (ft_error(MEM_ERR));
	if (!ft_init(data, philos))
		return (ft_free_philos(philos), EXIT_FAILURE);
	if (data->time_to_die == 0)
		printf("%d: philo %d died\n", 0, philos[0].philo_id);
	else
		philo_simulation(philos);
	ft_destroy_all_mutexes(philos);
	ft_free_philos(philos);
	return (EXIT_SUCCESS);
}
