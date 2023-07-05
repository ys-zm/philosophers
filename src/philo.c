#include "philo.h"

int main(int argc, char **argv)
{
    t_var   data;

    if (argc != 5 && argc != 6)
        return (ft_error(ARG_ERR));
    if (!philo_input_check(argv, &data))
        return (ft_error(INPUT_ERR));
    return (EXIT_SUCCESS);
}