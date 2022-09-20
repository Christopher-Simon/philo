/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:16:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:17:03 by chsimon          ###   ########.fr       */
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

int	philo_eat(t_philo *philo)
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
