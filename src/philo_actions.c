#include "philo.h"

bool    ft_check_thread_creation(t_var *data)
{
    int check;

    pthread_mutex_lock(&data->philo_thread_mutex);
    check = data->total_philo_threads;
    pthread_mutex_unlock(&data->philo_thread_mutex);
    if (check != data->n_philos)
        return (false);
    return (true);
}


// i can only pass one argument to my action loop, but i want to know the index and have the data struct :)
void    *ft_action_loop(void *arg)
{
    t_var *data;

    data = (t_var *)arg;
    if (!ft_check_thread_creation(data))
        return (NULL);
    if (data->philos[i].p)
}