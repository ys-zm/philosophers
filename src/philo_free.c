#include "philo.h"

void    ft_free_philos(t_var *data)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        pthread_mutex_destroy(&data->philos[i].r_fork);
    }
    free(data->philos);
    free(data);
}