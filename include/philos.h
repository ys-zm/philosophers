#ifndef PHILOS_H  
#define PHILOS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //thread / mutex functions
#include <limits.h> // limits
#include <stdbool.h> // boolean true / false

typedef struct s_philos
{
    int status;
}   t_philos;

typedef struct  s_var
{
    t_philos    *philos;
    u_int32_t   n_philos;
    u_int32_t   time_to_eat;
    u_int32_t   time_to_sleep;
    u_int32_t   time_to_think;
}   t_var;



#endif