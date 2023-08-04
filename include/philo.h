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
#define	INFINITE -1;

typedef struct timeval t_timeval;

typedef enum s_err_msg
{
	SUCCESS,
	INPUT_ERR,
	MEM_ERR,
	THR_ERR,
	ARG_ERR,
	N_PHILO_ERR,
	MUTEX_ERR
}	ph_err_msg;

typedef enum s_status
{
	ALIVE,
	DEAD,
	FULL
}	ph_status;

typedef enum s_event
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
	DIE
}	ph_event;

// mutex protects a variable, doesnt have to be the variable
// mutex has to be there for anything that tries to edit data at the same time
// a thread that checks other threads
typedef struct s_philo
{
	int				philo_id;
	long			start_time_ms;
	ph_status		status;
	t_timeval		time_last_meal;
	bool			alive;
	pthread_t		philo_thread;
	int				eat_count;
	pthread_mutex_t	eat_count_mutex;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_var			*data;
}	t_philo;

typedef struct	s_var
{
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_timeval		start_time;
	int				n_meals;
	bool			is_dead;
	pthread_mutex_t	death;
	int				total_philo_threads;
	pthread_mutex_t	philo_thread_mutex;
}	t_var;


// philo.c

int			main(int argc, char **argv);

// philo_utils.c

void		ft_putstr_fd(char *str, int fd);

uint32_t	ft_strlen(char *str);

int			ft_atoi(char *str);

void		philo_print(t_philo *philo, ph_event event);

// philo_err.c

int			ft_error(int error_type);

// philo_input.c

bool		philo_input_check(char **argv, t_var *data);

// philo_free.c

void		ft_free_philos(t_var *data);

void    	ft_destroy_all_mutexes(t_var *data);

// philo_init.c

bool    	ft_init(t_var *data);

bool    	init_philo(t_var *data);

void		set_l_fork(t_philo *philos, int n_philos);

// philo_actions.c

long		get_time_ms(void);

void		ft_sleep_ms(long time_to_sleep);

long 		find_time_diff(long t1, long t2);

long    	convert_ms(t_timeval t);

// philo_simulation.c

void    	philo_simulation(t_var *data);

#endif
