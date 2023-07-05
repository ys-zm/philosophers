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
