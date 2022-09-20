/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:22:23 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:23:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	speak(t_philo *philo, t_params *params, char *msg)
{
	int	ret;

	sc_sem_wait(params->s_speak);
	sc_sem_wait(philo->s_death);
	ret = philo->death;
	sc_sem_post(philo->s_death);
	if (!ret)
		printf("%ld %d %s\n", \
get_time() - philo->init_time, philo->print_id, msg);
	sc_sem_post(params->s_speak);
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

int	philo_eat(t_philo *philo, t_params *params)
{
	int		ret;
	time_t	wait;

	take_fork(philo, params);
	ret = speak(philo, params, EAT);
	wait = update_cycle(philo) + philo->time_to_eat;
	if (!ret)
		net_usleep(wait);
	release_fork(params);
	return (ret);
}
