#include "philo.h"

bool    ft_death_status(t_philo *philo)
{
    bool death;

    // printf(" philo %d tyring to death lock\n", philo->philo_id);
    if (pthread_mutex_lock(&philo->data->death))
        printf("problem with lock\n");
    // printf("death locked\n");
    death = philo->data->is_dead == true;
    pthread_mutex_unlock(&philo->data->death);
    // printf("philo %d death unlocked\n", philo->philo_id);
    return (death);
}

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

bool    ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->r_fork);
    if (!ft_death_status(philo))
        philo_print(philo, TAKE_FORK);
    pthread_mutex_lock(philo->l_fork);
    if (!ft_death_status(philo))
    {
        philo_print(philo, TAKE_FORK);
        return (true);
    }
    return (false);
}

void    ft_drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void    ft_update_last_meal_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->time_last_meal_mutex);
    gettimeofday(&philo->time_last_meal, NULL);
    pthread_mutex_unlock(&philo->time_last_meal_mutex);
}

void    ft_update_meal_count(t_philo *philo)
{
    pthread_mutex_lock(&philo->meal_count_mutex);
    philo->meal_count++;
    pthread_mutex_unlock(&philo->meal_count_mutex);
}

bool    ft_eat(t_philo *philo)
{
    if (!ft_death_status(philo))
    {
        ft_update_last_meal_time(philo);
        philo_print(philo, EAT);
        ft_update_meal_count(philo);
        ft_sleep_ms(philo->data->time_to_eat);
        return (true);
    }
    return (false);
}

bool    ft_sleep(t_philo *philo)
{
    if (!ft_death_status(philo))
    {
        philo_print(philo, SLEEP);
        ft_sleep_ms(philo->data->time_to_sleep);
        return (true);
    }
    return (false);
}
// i can only pass one argument to my action loop, but i want to know the index and have the data struct :)
// check if is dead is false then print.
void    *ft_action_loop(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (!ft_check_thread_creation(philo->data))
        return (NULL);
    usleep(100);
    ft_update_last_meal_time(philo);
    if (philo->philo_id % 2 == 1)
        usleep(100);
    while (philo->status == ALIVE)
    {
        if (!ft_take_forks(philo))
            break ;
        if (!ft_eat(philo))
            break;
        ft_drop_forks(philo);
        if (!ft_sleep(philo))
            break ;
        if (!ft_death_status(philo))
            philo_print(philo, THINK);
        else
            break ;
    }
    return (NULL);
}