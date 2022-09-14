/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_semaphore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:36:33 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/08 10:44:50 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

sem_t	*sc_sem_open(const char *name, int oflag, mode_t mode, unsigned int value)
{
	sem_t *semaphore;

	semaphore = sem_open(name, oflag, mode, value); 
	if (!semaphore)
	{
		printf("failed init semaphore\n");
		return (NULL);
	}
	return (semaphore);
}

int	sc_sem_close(sem_t *sem)
{
	if (sem_close(sem) == -1)
	{
		printf("failed close semaphore\n");
		return (1);
	}
	return (0);
}

int	sc_sem_wait(sem_t *sem)
{
	if (sem_wait(sem) == -1)
	{
		printf("failed wait semaphore\n");
		return (1);
	}
	return (0);
}

int	sc_sem_post(sem_t *sem)
{
	if (sem_post(sem) == -1)
	{
		printf("failed post semaphore\n");
		return (1);
	}
	return (0);
}

int	sc_sem_unlink(const char *name)
{
	if (sem_unlink(name))
	{
		printf("failed unlink semaphore : %s\n", name);
		return (1);
	}
	return (0);
}
