#include "philo.h"

void    philo_check_dead(t_philo *philos)
{
    int i;
    int n_philos;
    int philos_done_eating;

    n_philos = philos->data->n_philos;
    while (1)
    {
        i = 0;
        i++; // to silent the error! for now
        philos_done_eating = 0;
        //check if each philo is done eating
        if (philos_done_eating == n_philos)
        {
            // if all have finished eating the correct number of times
            //only if there was a speicificed amount
        }
    }
}