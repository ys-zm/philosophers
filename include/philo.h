#ifndef PHILOS_H  
#define PHILOS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //thread/mutex functions
#include <limits.h> // limits
#include <stdbool.h> // boolean true/false


typedef enum err_msg
{
    SUCCESS,
    INPUT_ERR,
    MEM_ERR,
    THR_ERR,
    ARG_ERR
}   e_err_msg;

typedef struct s_philo
{
    int             philo_id;
    int             status;
    int             time_last_meal;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
}   t_philo;

typedef struct  s_var
{
    t_philo *philos;
    int     n_philos;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     n_meals;
}   t_var;


// philo_utils.c
void        ft_putstr_fd(char *str, int fd);

uint32_t    ft_strlen(char *str);

int         ft_atoi(char *str);

// philo_err.c
int         ft_error(int error_type);

//philo_input_check.c
bool philo_input_check(char **argv, t_var *data);

#endif