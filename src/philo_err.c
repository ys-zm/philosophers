#include "philo.h"

int ft_error(int error_type)
{
    if (error_type == INPUT_ERR)
    {
        ft_putstr_fd("Input error\n", 2);
        ft_putstr_fd("Input numbers between 1 - INT_MAX\n", 2);
        return (INPUT_ERR);
    }
    else if (error_type == MEM_ERR)
    {
        ft_putstr_fd("Malloc error\n", 2);
        return (MEM_ERR);
    }
    else if (error_type == THR_ERR)
    {
        ft_putstr_fd("Thread error\n", 2);
        return (THR_ERR);
    }
    else if (error_type == ARG_ERR)
    {
        ft_putstr_fd("Wrong number of arguments\n", 2);
        ft_putstr_fd("Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep\n", 2); 
        ft_putstr_fd("Optional: [number_of_times_each_philosopher_must_eat]\n", 2);
        return (ARG_ERR);
    }
    else if (error_type == N_PHILO_ERR)
    {
        ft_putstr_fd("Minimum number of philosopher is 1 and maximum number is 200\n", 2);
        return (N_PHILO_ERR);
    }
    return (SUCCESS);   
}
