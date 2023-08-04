#include "philo.h"

void    ft_free_philos(t_var *data)
{
    free(data->philos);
    free(data);
}

void    ft_destroy_all_mutexes(t_var *data)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        pthread_mutex_destroy(&data->philos[i].eat_count_mutex);
        pthread_mutex_destroy(&data->philos[i].r_fork);
        i++;
    }
    pthread_mutex_destroy(&data->philo_thread_mutex);
    pthread_mutex_destroy(&data->death);
}