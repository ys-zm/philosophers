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

bool init_philo(t_var *data)
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
        if (pthread_mutex_init(&philo->r_fork, NULL))
            return (ft_error(MUTEX_ERR), false);
        i++;
    }
    set_l_fork(data->philos, data->n_philos);
    return (true);
}