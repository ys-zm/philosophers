#include "philo.h"

long    convert_ms(t_timeval t)
{
    long    ms;

    ms = t.tv_sec * 1000 + t.tv_usec / 1000;\
    return (ms);
}

long find_time_diff(long t1, long t2)
{
    return (t1 - t2);
}

long get_time_ms(void)
{
    t_timeval       tv;
    long            ret;

    gettimeofday(&tv, NULL);
    ret = convert_ms(tv);
    return (ret);
}

void    ft_sleep_ms(long time_to_sleep)
{
    long start;
    long current;

    start = get_time_ms();
    current = start;
    while ((current - start) < time_to_sleep)
    {
        usleep(30);
        current = get_time_ms();
    }
}