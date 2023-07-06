#include "philo.h"

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
    if (!init_philo(data))
        return (ft_free_philos(data), EXIT_FAILURE);

    ft_sleep_ms(5000);

    return (EXIT_SUCCESS);
}