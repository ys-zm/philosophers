/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:13:59 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 14:52:58 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	single_philo_death(t_philo *philo, int time_to_die)
{
	long	time;

	philo_print(philo, TAKE_FORK);
	ft_sleep_ms(philo, time_to_die);
	time = find_time_diff(get_time_ms(), philo->data->start_time);
	printf("%ld: philo %d died\n", time, philo->philo_id);
}

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
	ft_free_philos(philos);
	return (EXIT_SUCCESS);
}