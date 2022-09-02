/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:51:16 by christopher       #+#    #+#             */
/*   Updated: 2022/09/01 19:47:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

pthread_mutex_t	*create_mutex(int nb)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = ft_calloc(sizeof(pthread_mutex_t), nb);
	if (!mutex)
		return (NULL);
	while (i < nb)
	{
		if (sc_pthread_mutex_init(&mutex[i], NULL))
		{
			while (--i >= 0)
				sc_pthread_mutex_destroy(&mutex[i]);
			return (NULL);
		}
		i++;
	}
	return (mutex);
}

int	attribute_mutex(t_philo **philo, t_params *params, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo[i]->fork = &params->m_fork[i];
		if (i + 1 == nb_philo)
			philo[i]->next_fork = &params->m_fork[0];
		else
			philo[i]->next_fork = &params->m_fork[i + 1];
		philo[i]->cycle = &params->m_cycle[i];
		i++;
	}
	return (0);
}

int	init_mutex(t_philo **philo, t_params *params, int nb_philo)
{
	params->m_fork = create_mutex(params->fork);
	if (!params->m_fork)
		return (1);
	params->m_cycle = create_mutex(params->fork);
	if (!params->m_cycle)
		return (destroy_params(params));
	if (sc_pthread_mutex_init(&params->m_death, NULL))
		return (destroy_params(params));
	if (sc_pthread_mutex_init(&params->m_stop, NULL))
		return (destroy_params(params));
	attribute_mutex(philo, params, nb_philo);
	return (0);
}
