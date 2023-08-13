#include "philo.h"

static int check_philos_done_eating(t_philo *philo)
{
    int n_meals;

    n_meals = philo->data->n_meals;
    pthread_mutex_lock(&philo->meal_count_mutex);
    if (n_meals != INFINITE && philo->meal_count == n_meals)
    {
        return (pthread_mutex_unlock(&philo->meal_count_mutex), 1);
    }
    return (pthread_mutex_unlock(&philo->meal_count_mutex), 0);
}

static  ph_status check_death(t_philo *philo)
{
    long time_last_meal_ms;
    long diff;

    pthread_mutex_lock(&philo->time_last_meal_mutex);
    time_last_meal_ms = convert_ms(philo->time_last_meal);
    diff = get_time_ms() - time_last_meal_ms;
    pthread_mutex_unlock(&philo->time_last_meal_mutex);
    if ((int)diff > philo->data->time_to_die)
        return (DEAD);
    return (ALIVE);
}

void    ft_death(t_philo *philo)
{
    long    now;

    now = find_time_diff(get_time_ms(), philo->start_time_ms);
    pthread_mutex_lock(&philo->data->death);
    philo->data->is_dead = true;
    printf("%ld: philo %d died\n", now, philo->philo_id);
    pthread_mutex_unlock(&philo->data->death);
}

static void ft_full(t_var *data)
{
    pthread_mutex_lock(&data->death);
    data->is_dead = true;
    pthread_mutex_unlock(&data->death);
}

void    philo_check_status(t_philo *philos)
{
    int i;
    int n_philos;
    int philos_done_eating;

    n_philos = philos->data->n_philos;
    while (1)
    {
        i = 0;
        philos_done_eating = 0;
        while (i < n_philos)
        {
            philos_done_eating += check_philos_done_eating(&philos[i]);
            philos[i].status = check_death(&philos[i]);
            if (philos[i].status == DEAD)
                return (ft_death(&philos[i]));
            i++;    
        }
        if (philos_done_eating == n_philos)
            return (ft_full(philos->data));
    }
}