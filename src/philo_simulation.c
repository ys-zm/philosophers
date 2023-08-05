#include "philo.h"

void    *ft_action_loop(void *arg)
{
    (void)arg;
    //eat, sleep, think!
    return (NULL);
}

bool    ft_create_threads(t_philo *philos)
{
    int i;
    int n_philos;

    n_philos = philos->data->n_philos;
    pthread_mutex_lock(&philos->data->philo_thread_mutex);
    i = 0;
    philos->data->total_philo_threads = 0;
    philos->data->is_dead = false;
    while (i < n_philos)
    {
        if (pthread_create(&philos[i].philo_thread, NULL, ft_action_loop, &philos[i]))
            break ;
        philos->data->total_philo_threads += 1;
        i++;
    }
    pthread_mutex_unlock(&philos->data->philo_thread_mutex);
    if (philos->data->total_philo_threads != n_philos)
        return (false);
    return (true);
}

bool    ft_join_threads(t_philo *philos)
{
    int i;

    i = 0;
    while (i < philos->data->total_philo_threads)
    {
        if (pthread_join(philos[i].philo_thread, NULL))
            return (false);
        i++;
    }
    return (true);
}

void    philo_simulation(t_philo *philos)
{
    if (!ft_create_threads(philos))
    {
        ft_destroy_all_mutexes(philos);
        ft_free_philos(philos);
        printf("Error creating threads\n");
        return ;
    }
    philo_check_dead(philos);
    if (!ft_join_threads(philos))
        printf("Error joining threads\n");
}