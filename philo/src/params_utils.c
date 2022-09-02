/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:40:17 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 11:49:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	end_mutex(pthread_mutex_t *mutex, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		sc_pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
	return (0);
}

int	destroy_params(t_params *params)
{
	if (params->m_fork)
		end_mutex(params->m_fork, params->fork);
	if (params->m_cycle)
		end_mutex(params->m_cycle, params->fork);
	if (&params->m_death)
		sc_pthread_mutex_destroy(&params->m_death);
	if (&params->m_stop)
		sc_pthread_mutex_destroy(&params->m_stop);
	free(params);
	return (1);
}

int	kill_philos(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		free(philo_tab[i]);
		i++;
	}
	free(philo_tab);
	return (0);
}

int	destroy_philo(t_philo **philo_tab, int nb_philo)
{
	destroy_params(philo_tab[0]->params);
	kill_philos(philo_tab, nb_philo);
	return (0);
}
