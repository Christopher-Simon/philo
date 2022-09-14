/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:42:37 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/13 22:36:51 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	saint_kro_start(t_philo *philo)
{
	time_t	time;

	time = 1;
	while (time > 0)
	{
		time = philo->init_time - get_time();
		if (time > 1000)
			usleep(500);
		else if (time > 0)
			usleep(100);
	}
	return (0);
}

int	net_usleep(time_t time_to_wait)
{
	time_t	time;

	time = 1;
	while (time > 0)
	{
		time = time_to_wait - get_time();
		if (time > 1000)
			usleep(500);
		else if (time > 0)
			usleep(200);
	}
	return (0);
}

time_t	update_cycle(t_philo *philo)
{
	time_t	cycle;

	// pthread_mutex_lock(philo->cycle);
	cycle = get_time();
	sc_sem_wait(philo->s_cycle);
	philo->cycle_time = cycle;
	sc_sem_post(philo->s_cycle);
	// pthread_mutex_unlock(philo->cycle);
	return (cycle);
}
