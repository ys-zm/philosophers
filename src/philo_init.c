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

bool    init_philo(t_var *data, t_philo *philos)
{   
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        philos[i].status = ALIVE;
        philos[i].philo_id = i + 1;
        philos[i].data = data;
        philos[i].meal_count = 0;
        i++;
    }
    data->is_dead = false;
    return (true);
}

bool    init_philo_mutexes(t_philo *philos)
{
    int i;
    int n_philos;
    t_philo *philo;

    i = 0;
    n_philos = philos->data->n_philos;
    while (i < n_philos)
    {
        philo = &philos[i];
        if (pthread_mutex_init(&philo->r_fork, NULL))
            return (ft_error(MUTEX_ERR), false);
        if (pthread_mutex_init(&philo->meal_count_mutex, NULL))
            return (ft_error(MUTEX_ERR), false);
        if (pthread_mutex_init(&philo->time_last_meal_mutex, NULL))
            return (ft_error(MUTEX_ERR), false);
        if (pthread_mutex_init(&philo->time, NULL))
            return (ft_error(MUTEX_ERR), false);
        i++;
    }
    set_l_fork(philos, n_philos);
    return (true);
}

bool    init_data_mutexes(t_philo *philos)
{
    if (pthread_mutex_init(&philos->data->philo_thread_mutex, NULL))
        return (false);
    if (pthread_mutex_init(&philos->data->death, NULL))
    {
        pthread_mutex_destroy(&philos->data->philo_thread_mutex);
        return (false);
    }
    return (true);
}

bool    init_all_mutexes(t_philo *philos)
{
    if (!init_data_mutexes(philos))
        return (false);
    if (!init_philo_mutexes(philos))
    {
        ft_destroy_all_mutexes(philos);
        return (false);
    }
    return (true);
}

bool    ft_init(t_var *data, t_philo *philos)
{
    if (!init_philo(data, philos))
        return (false);
    if (!init_all_mutexes(philos))
        return (false);
    return (true);
}