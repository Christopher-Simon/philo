/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:03:17 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/02 18:32:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	remove_semaphores(void)
{
	if (sem_open(FORK, 0)) 
		return (sc_sem_unlink(FORK), 1);
	if (sem_open(SPEAK, 0))
		return (sc_sem_unlink(SPEAK), 1);
	return (0);
}

int init_semaphore(t_params *params, int nb_philo)
{
	remove_semaphores();
	params->s_fork = sc_sem_open(FORK, O_CREAT, 0755, nb_philo);
	if (!params->s_fork)
		return (1);
	params->s_speak = sc_sem_open(FORK, O_CREAT, 0755, nb_philo);
	if (!params->s_speak)
		return (remove_semaphores(), 1);
	return (0);
}
