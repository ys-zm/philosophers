#include "philo.h"

//giving a negative result...
int get_time_ms(void)
{
    t_timeval       tv;
    uint32_t            ret;

    gettimeofday(&tv, NULL);
    ret = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("ret: %ud\n", ret);
    return (ret);
}

void    ft_sleep_ms(int time_to_sleep)
{
    int start;
    int current;

    start = get_time_ms();
    current = start;
    printf("start: %d\n", start);
    while ((current - start) < time_to_sleep)
    {
        usleep(50);
        current = get_time_ms();
    }
    printf("diff %d\n", current - start);
    printf("curr time: %d\n", current);
}