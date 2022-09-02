/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:33:46 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 11:47:47 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	speak(t_philo *philo, char *msg)
{
	int	ret;

	pthread_mutex_lock(&philo->params->m_death);
	ret = philo->params->death;
	if (!ret)
		printf("%ld %d %s\n", \
get_time() - philo->init_time, philo->print_id, msg);
	pthread_mutex_unlock(&philo->params->m_death);
	return (ret);
}

int	philo_inception(t_philo *philo)
{
	int		ret;
	time_t	wait;

	ret = speak(philo, SLEEP);
	wait = get_time() + philo->time_to_sleep;
	if (!ret)
		net_usleep(wait);
	if (!ret)
		ret = speak(philo, THINK);
	if (philo->impair)
	{
		wait = wait + philo->time_to_eat;
		if (!ret)
			net_usleep(wait);
	}
	return (ret);
}

int	action_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	ret;

	pthread_mutex_lock(fork);
	ret = speak(philo, TAKE);
	if (ret)
		pthread_mutex_unlock(fork);
	return (ret);
}

int	take_fork(t_philo *philo, pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	if (action_fork(philo, fork_1))
		return (1);
	if (action_fork(philo, fork_2))
		return (pthread_mutex_unlock(fork_1), 1);
	return (0);
}

void	release_fork(pthread_mutex_t *fork_1, pthread_mutex_t *fork_2)
{
	pthread_mutex_unlock(fork_1);
	pthread_mutex_unlock(fork_2);
}

int		philo_eat(t_philo *philo)
{
	int		ret;
	time_t	wait;

	if (philo->print_id % 2 == 0)
		ret = take_fork(philo, philo->fork, philo->next_fork);
	else
		ret = take_fork(philo, philo->next_fork, philo->fork);
	if (ret)
		return (ret);
	ret = speak(philo, EAT);
	wait = update_cycle(philo) + philo->time_to_eat;
	if (!ret)
		net_usleep(wait);
	if (philo->print_id % 2 == 0)
		release_fork(philo->fork, philo->next_fork);
	else
		release_fork(philo->next_fork, philo->fork);
	return (ret);
}

void	la_vie_du_philo(t_philo *philo, t_params *params)
{
	if (philo->id % 2 != 1)
	{
		speak(philo, THINK);
		usleep(10000);
	}
	while (philo->round != 0)
	{
		if (philo_eat(philo))
			break ;
		if (philo->round != -1)
			philo->round--;
		if (philo->round == 0)
		{
			philo->round--;
			pthread_mutex_lock(&params->m_stop);
			params->stop++;
			pthread_mutex_unlock(&params->m_stop);
			break ;
		}
		if (philo_inception(philo))
			break ;
	}
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_params	*params;

	philo = (t_philo *)arg;
	params = philo->params;
	if (DB_PRMS_TH)
	{
		pthread_mutex_lock(&params->m_death);
		printf("IN THREAD %d\n", philo->id);
		print_philo(philo);
		pthread_mutex_unlock(&params->m_death);
	}
	saint_kro_start(philo);
	if (philo->nb_philo == 1)
		return (speak(philo, TAKE), NULL);
	la_vie_du_philo(philo, params);
	return (NULL);
}
