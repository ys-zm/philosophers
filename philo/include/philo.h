/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 18:39:58 by yzaim         #+#    #+#                 */
/*   Updated: 2023/08/31 18:57:50 by yzaim         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h> //thread/mutex functions
# include <limits.h> // limits
# include <stdbool.h> // boolean true/false
# include <sys/time.h> //get time of day

# define MAX_PHILO 200
# define MIN_PHILO 1
# define INFINITE -1

typedef struct timeval	t_timeval;

typedef struct s_var	t_var;

typedef enum s_err_msg
{
	SUCCESS,
	INPUT_ERR,
	MEM_ERR,
	THR_ERR,
	ARG_ERR,
	N_PHILO_ERR,
	MUTEX_ERR
}	t_err_msg;

typedef enum s_status
{
	DEAD,
	ALIVE
}	t_status;

typedef enum s_event
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
	DIE
}	t_event;

typedef struct s_philo
{
	int				philo_id;
	size_t			last_meal;
	pthread_t		philo_thread;
	int				meal_count;
	bool			full;
	pthread_mutex_t	meal_count_mutex; // remove meal count
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_var			*data;
}	t_philo;

typedef struct s_var
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	bool			is_dead;
	size_t			start_time;
	int				total_philo_threads;
	pthread_mutex_t	start;		//start the threads & check thread creation!
	// pthread_mutex_t	print_mutex; // maybe not needed		
	pthread_mutex_t	death; // death used by all
	pthread_mutex_t	time;		// time used by all/ watcher thread
	pthread_mutex_t	alive_philo_mutex[201];
	bool			alive_philos[201];
}	t_var;


// philo.c

void			single_philo_death(t_philo *philo, int time_to_die);

int				main(int argc, char **argv);

// philo_utils.c

void			ft_putstr_fd(char *str, int fd);

uint32_t		ft_strlen(char *str);

int				ft_atoi(char *str);

bool			philo_print(t_philo *philo, t_event event);

void			print_msg(int philo_id, long now, t_event event);

// philo_err.c

int				ft_other_errors(int error_type);

int				ft_error(int error_type);

// philo_input.c

bool			philo_input_check(char **argv, t_var *data);

// philo_free.c

void			ft_free_philos(t_philo *philos);

void			ft_destroy_all_mutexes(t_philo *philos);

// philo_init.c

bool			ft_init(t_var *data, t_philo *philos);

bool			init_philo(t_var *data, t_philo *philos);

void			set_l_fork(t_philo *philos, int n_philos);

// philo_init_mutex.c

bool			init_all_mutexes(t_philo *philos);

bool			init_data_mutexes(t_philo *philos);

bool			init_philo_mutexes(t_philo *philos);

// philo_time.c

size_t			get_time_ms(void);

void			ft_sleep_ms(t_philo *philo, long long time_to_sleep);

long			find_time_diff(long t1, long t2);

size_t	convert_ms(t_timeval t);

// philo_simulation.c

void			philo_simulation(t_philo *philos);

bool			ft_join_threads(t_philo *philos);

bool			ft_create_threads(t_philo *philos);

void			*ft_action_loop(void *arg);

// philo_death.c

void			philo_check_status(t_philo *philos);

void			ft_death(t_philo *philo);

// philo_death_status.c

bool			ft_death_status(t_philo *philo);

bool	ft_check_live_philo(t_philo *philo);

// philo_actions.c

bool			ft_take_forks(t_philo *philo);

void			ft_drop_forks(t_philo *philo);

t_status		check_death(t_philo *philo);

bool			ft_eat(t_philo *philo);

bool			ft_sleep(t_philo *philo);

// philo_actionloop.c

bool			ft_check_thread_creation(t_var *data);

void			ft_update_last_meal_time(t_philo *philo);

bool			ft_update_meal_count(t_philo *philo);

void			*ft_action_loop(void *arg);

#endif
