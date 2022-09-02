/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:40:17 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 18:33:06 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	destroy_semaphores(t_params *params)
{
	if (params->s_fork)
		sc_sem_close(params->s_fork);
	if (params->s_speak)
		sc_sem_close(params->s_speak);
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
	destroy_semaphores(philo_tab[0]->params);
	free(philo_tab[0]->params);
	kill_philos(philo_tab, nb_philo);
	return (0);
}
