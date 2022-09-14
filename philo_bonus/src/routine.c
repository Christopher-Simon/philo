/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:33:46 by christopher       #+#    #+#             */
/*   Updated: 2022/09/13 16:31:55 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	speak(t_philo *philo, t_params *params, char *msg)
{
	int		ret;
	time_t	wait_time;

	wait_time = get_time();
	sc_sem_wait(params->s_speak);
	if (get_time() - wait_time > 50)
		philo->death = 0;
	ret = philo->death;
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
		{
			philo->round--;
		}
		if (philo->round == 0)
		{
			philo->death = 1;

		// 	philo->round--;
		// 	pthread_mutex_lock(&params->m_stop);
		// 	params->stop++;
		// 	pthread_mutex_unlock(&params->m_stop);
		// 	break ;
		}
		if (philo_inception(philo, params))
			break ;
	}
}

int	routine(t_philo *philo, t_params *params)
{
	
	if (DB_FORK)
	{
		// print_philo(philo);
	}
	// if (philo->nb_philo == 1)
	// 	return (speak(philo, params, TAKE), NULL);
	t_shinigami	shini;
	pthread_t	th_shinigami;

	shini.philo = philo;
	shini.time_to_die = philo->time_to_die;
	shini.nb_philo = philo->nb_philo;
	if (sc_pthread_create(&th_shinigami, NULL, shinigami, &shini))
		return (1); //PROCEDURE ARRET DES AUTRES Philo
	saint_kro_start(philo);
	la_vie_du_philo(philo, params);
	sc_pthread_join(th_shinigami, NULL);
	// test_sema(philo, params);
	return (0);
}
