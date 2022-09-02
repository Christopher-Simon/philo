/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:59:02 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 11:45:41 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	sc_pthread_mutex_init(pthread_mutex_t *restrict mutex,
const pthread_mutexattr_t *restrict attr)
{
	if (pthread_mutex_init(mutex, attr))
	{
		printf("failed init mutex\n");
		return (1);
	}
	return (0);
}

int	sc_pthread_mutex_destroy(pthread_mutex_t *restrict mutex)
{
	if (pthread_mutex_destroy(mutex))
	{
		printf("failed destroy mutex\n");
		return (1);
	}
	return (0);
}

int	sc_pthread_mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{
		printf("failed lock mutex\n");
		return (1);
	}
	return (0);
}

int	sc_pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{
		printf("failed unlock mutex\n");
		return (1);
	}
	return (0);
}
