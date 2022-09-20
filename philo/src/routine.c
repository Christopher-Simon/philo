/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:33:46 by christopher       #+#    #+#             */
/*   Updated: 2022/09/20 16:16:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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
