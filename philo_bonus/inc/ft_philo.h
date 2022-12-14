/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:52:20 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:25:45 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h> 
# include <errno.h>
# include <fcntl.h>

# define TAKE	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define DIE	"died"
# define THINK	"is thinking"

# define CYCLE		"SEMAPHORE_PHILO_CYCLE_"
# define DEATH		"SEMAPHORE_PHILO_DEATH_"
# define FORK		"SEMAPHORE_PHILO_FORK"
# define SPEAK		"SEMAPHORE_PHILO_SPEAK"
# define SNOWDEN	"SEMAPHORE_PHILO_SNOWDEN"
# define ALL		"SEMAPHORE_PHILO_ALL"
# define ROUND		"SEMAPHORE_PHILO_ROUND"
# define END		"SEMAPHORE_PHILO_END"
# define P_END		"SEMAPHORE_PHILO_P_END"

# define START_DELAY 500
# define GROUP_2_DELAY 60000

//DEFINE DEBUG

# define DB_PARAMS	0
# define DB_PHILO	0
# define DB_FORK	0
# define DB_HADES	0

typedef struct s_params
{
	sem_t			*s_fork;
	int				fork;
	sem_t			*s_speak;
	sem_t			*s_nowden;
	sem_t			*s_all;
	int				nb_philo;
	int				death;
	int				stop;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	sem_t			*s_round;
	int				round;
	sem_t			*s_end;
	sem_t			*s_p_end;
	int				end;
	time_t			init_time;
}	t_params;

typedef struct s_philo
{
	sem_t			*s_cycle;
	sem_t			*s_death;
	int				death;
	char			*name_death;
	int				id;
	int				print_id;
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
	char			*cycle;
}	t_philo;

typedef struct s_shinigami
{
	t_philo	*philo;
	int		time_to_die;
	int		nb_philo;
}	t_shinigami;

//SECURED THREADING
int			sc_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
				void *(*start_routine) (void *), void *arg);
int			sc_pthread_join(pthread_t thread, void **retval);

//SECURED TIME
int			sc_gettimeofday(struct timeval *restrict tv,
				struct timezone *restrict tz);

//INIT
t_params	*get_params(char **argv);
int			validator(char **argv);
t_philo		**init_struct_philo(char **argv);
int			destroy_philo(t_philo **philo, t_params *params, int nb_philo);
int			destroy_semaphores(t_philo **philo_tab, t_params *params, \
int nb_philo);
int			remove_semaphores(t_philo **philo_tab, int nb_philo);
int			init_semaphore(t_philo **philo_tab, t_params *params, int nb_philo);

//INIT DB
void		print_params(t_params *params);
void		print_philo(t_philo *philo);
void		print_all_philo(t_philo **philo, int nb_philo);

//TIME
time_t		get_time(void);
time_t		get_elapsed_time(suseconds_t time1, suseconds_t time2);

//THREADATOR
int			threadator(t_philo **philo, t_params *params, int nb_philo);
int			create_shinigami(t_philo *philo, pthread_t *th_philo, int nb_philo);

//FORKATOR
int			forkator(t_philo **philo_tab, t_params *params, int nb_philo);
int			create_fork(t_philo **philo_tab, t_params *params, int nb_philo);
int			end_forks(int *id, int nb_philo);
void		create_fork2(t_philo **philo_tab, t_params *params,
				int nb_philo, int *id);

//THREAD UTILS
int			end_philo_thread(int nb, pthread_t *thread);
int			create_thread(t_philo **philo, pthread_t *thread, int nb_philo);

//SEMAPHORE UTILS
int			sc_sem_close(sem_t *sem);
sem_t		*sc_sem_open(const char *name, int oflag,
				mode_t mode, unsigned int value);
int			sc_sem_post(sem_t *sem);
int			sc_sem_unlink(const char *name);
int			sc_sem_wait(sem_t *sem);

//ROUTINE
int			routine(t_philo *philo, t_params *params);
int			speak(t_philo *philo, t_params *params, char *msg);
int			saint_kro_start(t_philo *philo);
int			is_dead(t_philo philo);
int			is_one_dead(t_philo philo);
time_t		update_cycle(t_philo *philo);
int			net_usleep(time_t time_to_wait);
int			philo_eat(t_philo *philo, t_params *params);

//SHINIGAMI
void		*shinigami(void *arg);
int			init_shinigami(t_philo *philo);

//SNOWDEN
void		*snowden(void *arg);
int			activate_snowden(t_params *params, int nb_philo);

//UTILS
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int c);

#endif