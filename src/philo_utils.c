/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:15:20 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/24 18:15:23 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	ft_strlen(char *str)
{
	uint32_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	ft_atoi(char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	if (!str || str[0] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || ret > INT_MAX)
		return (-1);
	return (ret);
}

bool	philo_print(t_philo *philo, ph_event event)
{
	long	now;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (ft_death_status(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (false);
	}
	if (event == EAT)
	{
		now = find_time_diff(get_time_ms(), philo->start_time_ms);
		printf("%ld: philo %d is eating\n", now, philo->philo_id);
	}
	else if (event == THINK)
	{
		now = find_time_diff(get_time_ms(), philo->start_time_ms);
		printf("%ld: philo %d is thinking\n", now, philo->philo_id);
	}
	else if (event == SLEEP)
	{
		now = find_time_diff(get_time_ms(), philo->start_time_ms);
		printf("%ld: philo %d is sleeping\n", now, philo->philo_id);
	}
	else if (event == TAKE_FORK)
	{
		now = find_time_diff(get_time_ms(), philo->start_time_ms);
		printf("%ld: philo %d has taken a fork\n", now, philo->philo_id);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (true);
}
