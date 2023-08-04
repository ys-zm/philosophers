#include "philo.h"

void    single_philo_death(t_philo *philo, int time_to_die)
{
    philo_print(philo, TAKE_FORK);
    ft_sleep_ms(time_to_die);
    philo_print(philo, DIE);
}

bool    ft_set_start_time(t_var *data)
{
    int     i;
    long    st_ms;

    i = 0;
    if (gettimeofday(&data->start_time, NULL))
        return (1);
    st_ms = convert_ms(data->start_time);
    while (i < data->n_philos)
    {
        data->philos[i].start_time_ms = st_ms;
        i++;
    }
    return (0);
}

//need to create my ft_sleep_ms function to sleep a desired amount of ms
int main(int argc, char **argv)
{
    t_var   *data;

    if (argc != 5 && argc != 6)
        return (ft_error(ARG_ERR));
    data = malloc(sizeof(t_var) * 1);
    if (!data)
        return (ft_error(MEM_ERR));    
    if (!philo_input_check(argv, data))
        return (free(data), ft_error(INPUT_ERR));
    if (data->n_philos < MIN_PHILO || data->n_philos > MAX_PHILO)
        return (free(data), ft_error(N_PHILO_ERR));
    if (!ft_init(data))
        return (ft_free_philos(data), EXIT_FAILURE);
    if (ft_set_start_time(data))
        return (printf("Get time failed\n"), EXIT_FAILURE);
    if (data->time_to_die == 0)
        philo_print(&data->philos[0], DIE);
    else if (data->n_philos == 1)
        single_philo_death(&data->philos[0], data->time_to_die);
    else
        philo_simulation(data);
    return (EXIT_SUCCESS);
}