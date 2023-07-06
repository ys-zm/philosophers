#include "philo.h"

int get_time_ms(void)
{
    struct timeval tv;
    int             ret;

    gettimeofday(&tv, NULL);
    printf("s: %ld\n", tv.tv_sec);
    printf("ms: %d\n", tv.tv_usec);
    
    ret = tv.tv_sec * 1000 + tv.tv_usec;
    printf("ret: %d\n", ret);
    return (ret);
}

void    ft_sleep_ms(int time_to_sleep)
{
    int start;
    int current;

    start = get_time_ms();
    current = start;
    while ((current - start) < time_to_sleep)
    {
        usleep(10);
        current = get_time_ms();
        printf("curr=start: %d\n", current - start);
    }
}