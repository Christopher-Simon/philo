/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:33:46 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 18:19:44 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	speak(t_philo *philo, char *msg)
{
	int	ret;

	ret = philo->params->death;
	if (!ret)
		printf("%ld %d %s\n", 
get_time() - philo->init_time, philo->print_id, msg);
	return (ret);
}

// int	philo_inception(t_philo *philo)
// {
// 	int		ret;
// 	time_t	wait;

// 	ret = speak(philo, SLEEP);
// 	wait = get_time() + philo->time_to_sleep;
// 	if (!ret)
// 		net_usleep(wait);
// 	if (!ret)
// 		ret = speak(philo, THINK);
// 	if (philo->impair)
// 	{
// 		wait = wait + philo->time_to_eat;
// 		if (!ret)
// 			net_usleep(wait);
// 	}
// 	return (ret);
// }

int	take_fork(t_philo *philo, t_params *params)
{
	sem_wait(params->s_fork);
	speak(philo, TAKE);
	sem_wait(params->s_fork);
	speak(philo, TAKE);
	return (0);
}

void	release_fork(t_params *params)
{
	sem_post(params->s_fork);
	sem_post(params->s_fork);
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
	ret = speak(philo, EAT);
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
		speak(philo, THINK);
		usleep(GROUP_2_DELAY);
	}
	while (philo->round != 0)
	{
		if (philo_eat(philo, params))
			break ;
		if (philo->round != -1)
			philo->round--;
		// if (philo->round == 0)
		// {
		// 	philo->round--;
		// 	pthread_mutex_lock(&params->m_stop);
		// 	params->stop++;
		// 	pthread_mutex_unlock(&params->m_stop);
		// 	break ;
		// }
		// if (philo_inception(philo))
		// 	break ;
	}
}

int	routine(t_philo *philo, t_params *params)
{
	
	if (DB_FORK)
	{
		printf("IN THREAD %d\n", philo->id);
		// print_philo(philo);
	}
	// if (philo->nb_philo == 1)
	// 	return (speak(philo, TAKE), NULL);
	
	saint_kro_start(philo);
	la_vie_du_philo(philo, params);
	return (0);
}
