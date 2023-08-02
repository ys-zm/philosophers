#include "philo.h"

uint32_t    ft_strlen(char *str)
{
    uint32_t    count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

void    ft_putstr_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

int ft_atoi(char *str)
{
    int     i;
    long    ret;

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

void    philo_print(t_philo *philo, ph_event event)
{
    int   now;

    now = get_time_ms();
    if (event == EAT)
        printf("%d: philo %d is eating\n", now, philo->philo_id);
    else if (event == THINK)
        printf("%d: philo %d is thinking\n", now, philo->philo_id);
    else if (event == SLEEP)
        printf("%d: philo %d is sleeping\n", now, philo->philo_id);
    else if (event == TAKE_FORK)
        printf("%d: philo %d took a fork\n", now, philo->philo_id);
    else if (event == DIE)
        printf("%d: philo %d died\n", now, philo->philo_id);
}
