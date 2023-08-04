#include "philo.h"

void    set_l_fork(t_philo *philos, int n_philos)
{
    int i;

    i = 1;
    while (i < n_philos)
    {
        philos[i].l_fork = &philos[i - 1].r_fork;
        i++;
    }
    philos[0].l_fork = &philos[i - 1].r_fork;
}

bool    init_philo(t_var *data)
{   
    t_philo *philo;

    int i;

    i = 0;
    data->philos = malloc(sizeof(t_philo) * data->n_philos);
    if (!data->philos)
        return (ft_error(MEM_ERR), false);
    while (i < data->n_philos)
    {
        philo = &data->philos[i];
        philo->status = ALIVE;
        philo->philo_id = i + 1;
        i++;
    }
    return (true);
}

bool    init_philo_mutexes(t_var *data)
{
    int i;
    t_philo *philo;

    i = 0;
    while (i < data->n_philos)
    {
        philo = &data->philos[i];
        if (pthread_mutex_init(&philo->r_fork, NULL))
            return (ft_error(MUTEX_ERR), false);
        if (pthread_mutex_init(&philo->eat_count_mutex, NULL))
            return (ft_error(MUTEX_ERR), false);
        i++;
    }
    set_l_fork(data->philos, data->n_philos);
    return (true);
}

bool    init_data_mutexes(t_var *data)
{
    if (pthread_mutex_init(&data->philo_thread_mutex))
        return (false);
    if (pthread_mutex_init(&data->death))
    {
        pthread_mutex_destroy(&data->philo_thread_mutex);
        return (false);
    }
    return (true);
}

bool    init_all_mutexes(t_var *data)
{
    if (!init_data_mutexes(data))
    {
        return (false);
    }
    if (!init_philo_mutexes(data))
    {
        ft_destroy_all_mutexes(data);
        return (false);
    }
    return (true);
}

bool    ft_init(t_var *data)
{
    if (!init_philo(data))
        return (false);
    if (!init_all_mutexes(data))
        return (false);
    return (true);
}