/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_threading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/08/01 10:34:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	sc_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
void *(*start_routine) (void *), void *arg)
{
	if (pthread_create(thread, attr, start_routine, arg))
	{
		printf("failed creating thread");
		return (1);
	}
	return (0);
}

int	sc_pthread_join(pthread_t thread, void **retval)
{
	if (pthread_join(thread, retval))
	{
		printf("failed joining thread");
		return (1);
	}
	return (0);
}