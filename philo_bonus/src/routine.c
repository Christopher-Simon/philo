/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:33:46 by christopher       #+#    #+#             */
/*   Updated: 2022/09/16 17:55:57 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

//Pour le check de la mort, utiliser un 3eme thread, bloqué à un wait (sem init à 0)
//Quand un philo meurt, il post, ce qui débloque les autres et met death à 1. 

int	speak(t_philo *philo, t_params *params, char *msg)
{
	int		ret;

	sc_sem_wait(params->s_speak);
	sc_sem_wait(philo->s_death);
	ret = philo->death;
	sc_sem_post(philo->s_death);
	if (!ret)
		printf("%ld %d %s\n", 
get_time() - philo->init_time, philo->print_id, msg);
	sc_sem_post(params->s_speak);
	return (ret);
}

int	philo_inception(t_philo *philo, t_params *params)
{
	int		ret;
	time_t	wait;

	ret = speak(philo, params, SLEEP);
	wait = get_time() + philo->time_to_sleep;
	if (!ret)
		net_usleep(wait);
	if (!ret)
		ret = speak(philo, params, THINK);
	if (philo->impair)
	{
		wait = wait + philo->time_to_eat;
		if (!ret)
			net_usleep(wait);
	}
	return (ret);
}

int	take_fork(t_philo *philo, t_params *params)
{
	sc_sem_wait(params->s_fork);
	speak(philo, params, TAKE);
	sc_sem_wait(params->s_fork);
	speak(philo, params, TAKE);
	return (0);
}

void	release_fork(t_params *params)
{
	sc_sem_post(params->s_fork);
	sc_sem_post(params->s_fork);
}

int		philo_eat(t_philo *philo, t_params *params)
{
	int		ret;
	time_t	wait;

	// if (philo->print_id % 2 == 0)
	// 	ret = take_fork(philo, philo->fork, philo->next_fork);
	// else
	// 	ret = take_fork(philo, philo->next_fork, philo->fork);
	// if (ret)
	// 	return (ret);
	take_fork(philo, params);
	ret = speak(philo, params, EAT);
	wait = update_cycle(philo) + philo->time_to_eat;
	if (!ret)
		net_usleep(wait);
	release_fork(params);
	return (ret);
}

void	la_vie_du_philo(t_philo *philo, t_params *params)
{
	if (philo->id % 2 != 1)
	{
		speak(philo, params, THINK);
		usleep(GROUP_2_DELAY);
	}
	while (philo->round != 0)
	{
		if (philo_eat(philo, params))
			break ;
		if (philo->round != -1)
			philo->round--;
		if (philo->round == 0)
		{
			philo->round--;
			sem_post(params->s_round);
		}
		if (philo_inception(philo, params))
			break ;
	}
}

void	failed_launch(t_philo *philo, t_params *params, pthread_t th_shinigami)
{
	printf("FAILED_LAUNCH\n");
	saint_kro_start(philo);
	sc_sem_wait(params->s_speak);
	sc_sem_wait(philo->s_death);
	philo->death = 1;
	sc_sem_post(philo->s_death);
	sc_sem_post(params->s_speak);
	sc_sem_post(philo->params->s_nowden);
	sc_sem_post(philo->params->s_round);
	sc_pthread_join(th_shinigami, NULL);
}

void	routine_solo(t_philo *philo, t_params *params)
{
	time_t	wait;

	saint_kro_start(philo);
	speak(philo, params, TAKE);
	wait = get_time() + philo->time_to_die;
	net_usleep(wait);
	speak(philo, params, DIE);
	sc_sem_post(philo->params->s_end);
	sc_sem_post(philo->params->s_round);
}

int	routine(t_philo *philo, t_params *params)
{
	if (DB_FORK)
	{
		printf("in philo\n");
		// print_philo(philo);
	}
	t_shinigami	shini;
	pthread_t	th_shinigami;
	pthread_t	th_snowden;

	shini.philo = philo;
	shini.time_to_die = philo->time_to_die;
	shini.nb_philo = philo->nb_philo;
	if (philo->nb_philo == 1)
		return (routine_solo(philo, params), 0);
	if (sc_pthread_create(&th_shinigami, NULL, shinigami, &shini))
	{
		printf("FAILED THREAD SHINI\n");
		return (sc_sem_post(philo->params->s_nowden), 1); //PROCEDURE ARRET DES AUTRES Philo
	}
	if (sc_pthread_create(&th_snowden, NULL, snowden, philo))
		return (failed_launch(philo, params, th_shinigami), 1);	
	saint_kro_start(philo);
	la_vie_du_philo(philo, params);
	sc_pthread_join(th_shinigami, NULL);
	sc_pthread_join(th_snowden, NULL);
	// test_sema(philo, params);
	return (0);
}
