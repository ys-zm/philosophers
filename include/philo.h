#ifndef PHILOS_H  
#define PHILOS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //thread/mutex functions
#include <limits.h> // limits
#include <stdbool.h> // boolean true/false
#include <sys/time.h> //get time of day

#define MAX_PHILO 200
#define MIN_PHILO 1


typedef enum s_err_msg
{
    SUCCESS,
    INPUT_ERR,
    MEM_ERR,
    THR_ERR,
    ARG_ERR,
    N_PHILO_ERR, 
    MUTEX_ERR
}   ph_err_msg;

typedef enum s_status
{
    ALIVE, 
    DEAD,
    FULL
} ph_status;

typedef enum s_event
{
    EAT,
    SLEEP, 
    THINK,
    TAKE_FORK,
    DIE
}   ph_event;

typedef struct s_philo
{
    int             philo_id;
    ph_status       status;
    int             time_last_meal;
    pthread_mutex_t r_fork;
    pthread_mutex_t *l_fork;
    bool            alive;
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


// philo.c

int         main(int argc, char **argv);

// philo_utils.c

void        ft_putstr_fd(char *str, int fd);

uint32_t    ft_strlen(char *str);

int         ft_atoi(char *str);

void        philo_print(t_philo *philo, ph_event event);

// philo_err.c

int         ft_error(int error_type);

// philo_input.c

bool        philo_input_check(char **argv, t_var *data);

// philo_free.c

void        ft_free_philos(t_var *data);

// philo_init.c

bool        init_philo(t_var *data);

void        set_l_fork(t_philo *philos, int n_philos);

// philo_actions.c

int         get_time_ms(void);

void        ft_sleep_ms(int time_to_sleep);

#endif