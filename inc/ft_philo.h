/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:52:20 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/01 20:05:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include "ft_my_lib.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

# define TAKE	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define DIE	"died"
# define THINK	"is thinking"

# define PAIR		% 2 == 0
# define IMPAIR		% 2 == 1

//DEFINE DEBUG

# define DB_PARAMS	0
# define DB_PHILO	0
# define DB_PRMS_TH	0
# define DB_HADES	0



typedef struct s_params
{
	pthread_mutex_t	*m_fork;
	int				fork;
	int				nb_philo;
	pthread_mutex_t	*m_cycle;
	pthread_mutex_t	m_speak;
	pthread_mutex_t	m_death;
	int				death;
	pthread_mutex_t	m_stop;
	int				stop;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				round;
	time_t			init_time;
} t_params;

typedef struct s_philo
{
	int				id;
	int				print_id;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	*cycle;
	t_params		*params;
	time_t			init_time;
	time_t			cycle_time;
	time_t			sh_cycle_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				round;
	int				impair;
	int				nb_philo;
} t_philo;

typedef struct s_shinigami
{
	int	time_to_die;
	int	nb_philo;
} t_shinigami;

//SECURED THREADING

int			sc_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg);
int			sc_pthread_join(pthread_t thread, void **retval);

int			sc_pthread_mutex_init(pthread_mutex_t *restrict mutex, 
		const pthread_mutexattr_t *restrict attr);
int			sc_pthread_mutex_destroy(pthread_mutex_t *restrict mutex);

//SECURED TIME
int			sc_gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz);

//INIT
int			validator(char **argv);
t_philo		**init_struct_philo(char **argv);
int			destroy_params(t_params *params);
int			destroy_philo(t_philo **philo, int nb_philo);

//INIT DB
void		print_params(t_params *params);
void		print_philo(t_philo *philo);
void		print_all_philo(t_philo **philo, int nb_philo);

//INIT MUTEX
int			init_mutex(t_philo **philo, t_params *params, int nb_philo);
int			end_mutex(pthread_mutex_t *mutex, int nb);

//TIME
time_t		get_time();
time_t		get_elapsed_time(suseconds_t time1, suseconds_t time2);

//THREADATOR
int			threadator(t_philo **philo, t_params *params, int nb_philo);
int			create_shinigami(t_philo *philo, pthread_t *th_philo, int nb_philo);

//THREAD UTILS
int			end_philo_thread(int nb, pthread_t *thread);
int			create_thread(t_philo **philo, pthread_t *thread, int nb_philo);

//ROUTINE
void		*routine(void *arg);
int			speak(t_philo *philo, char *msg);
int			saint_kro_start(t_philo *philo);
int			is_dead(t_philo philo);
int			is_one_dead(t_philo philo);
time_t		update_cycle(t_philo *philo);
int			net_usleep(time_t time_to_wait);

int			shinigami(t_philo **philo, t_params *params, t_shinigami shini);
#endif