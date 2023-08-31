/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_time.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:15:11 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 16:25:41 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	convert_ms(t_timeval t)
{
	size_t	ms;

	ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (ms);
}

long	find_time_diff(long t1, long t2)
{
	return (t1 - t2);
}

size_t	get_time_ms(void)
{
	t_timeval	tv;
	size_t		ret;

	gettimeofday(&tv, NULL);
	ret = convert_ms(tv);
	return (ret);
}

void	ft_sleep_ms(t_philo *philo, long long time_to_sleep)
{
	long long	start;

	start = get_time_ms();
	while (ft_death_status(philo) ==  false)
	{
		if (((long long)get_time_ms() - start) >= time_to_sleep)
			break ;
		usleep(50);
	}
}
