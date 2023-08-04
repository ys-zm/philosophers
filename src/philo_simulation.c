#include "philo.h"

bool    ft_action_loop(t_var *data)
{
    //eat, sleep, think!
}

bool    ft_create_threads(t_var *data)
{
    int i;

    pthread_mutex_lock(&data->philo_thread_mutex);
    i = 0;
    data->total_philo_threads = 0;
    data->is_dead = false;
    while (i < data->n_philos)
    {
        if (pthread_create(&data->philos[i].philo_thread))
            break ;
        data->total_philo_threads += 1;
        i++;
    }
    pthread_mutex_unlock(&data->philo_thread_mutex);
    if (data->total_philo_threads != data->n_philos)
        return (false);
    return (true);
}

bool    ft_join_threads(t_var *data)
{
    int i;

    i = 0;
    while (i < data->total_philo_threads)
    {
        pthread_join(&data->philos[i].philo_thread, NULL);
        i++;
    }
}

void    philo_simulation(t_var *data)
{
    if (!ft_create_threads(data))
    {
        ft_destroy_all_mutexes(data);
        ft_free_philos(data);
        printf("Error creating threads\n");
        return ;
    }
    ft_check_if_dead(); //to stop the simulation when one dies
    ft_join_threads(data);
}