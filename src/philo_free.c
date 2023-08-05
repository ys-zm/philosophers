#include "philo.h"

void    ft_free_philos(t_philo *philos)
{
    free(philos->data);
    free(philos);
}

void    ft_destroy_all_mutexes(t_philo *philos)
{
    int i;
    int n_philos;

    i = 0;
    n_philos = philos->data->n_philos;
    while (i < n_philos)
    {
        pthread_mutex_destroy(&philos[i].eat_count_mutex);
        pthread_mutex_destroy(&philos[i].r_fork);
        i++;
    }
    pthread_mutex_destroy(&philos->data->philo_thread_mutex);
    pthread_mutex_destroy(&philos->data->death);
}