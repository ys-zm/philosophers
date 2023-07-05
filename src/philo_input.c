#include "philo.h"

bool philo_input_check(char **argv, t_var *data)
{
    if (!*argv[1] || !*argv[2] || !*argv[3] || !*argv[4])
        return (false);
    data->n_philos = ft_atoi(argv[1]);
    printf("nphilo: %d\n", data->n_philos);
    data->time_to_die = ft_atoi(argv[2]);
    printf("die: %d\n", data->time_to_die);
    data->time_to_eat = ft_atoi(argv[3]);
    printf("eat: %d\n", data->time_to_eat);
    data->time_to_sleep = ft_atoi(argv[4]);
    printf("sleep: %d\n", data->time_to_sleep);
    if (argv[5])
    {
        data->n_meals = ft_atoi(argv[5]);
        printf("nmeals: %d\n", data->n_meals);
    }
    else
        data->n_meals = -1;
    if (data->n_philos < 0 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
        return (false);
    if (argv[5] && data->n_meals < 0)
        return (false);
    return (true);
}