/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:40:17 by christopher       #+#    #+#             */
/*   Updated: 2022/09/16 15:38:34 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	destroy_semaphores(t_philo **philo_tab, t_params *params, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (philo_tab && philo_tab[i] && philo_tab[i]->s_cycle)
			sc_sem_close(philo_tab[i]->s_cycle);
		if (philo_tab && philo_tab[i] && philo_tab[i]->s_death)
			sc_sem_close(philo_tab[i]->s_death);
		i++;
	}
	if (params && params->s_fork)
		sc_sem_close(params->s_fork);
	if (params && params->s_speak)
		sc_sem_close(params->s_speak);
	if (params && params->s_nowden)
		sc_sem_close(params->s_nowden);
	if (params && params->s_all)
		sc_sem_close(params->s_all);
	if (params && params->s_round)
		sc_sem_close(params->s_round);
	if (params && params->s_end)
		sc_sem_close(params->s_end);
	if (params && params->s_p_end)
		sc_sem_close(params->s_p_end);
	return (1);
}

int	kill_philos(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (philo_tab && philo_tab[i] && philo_tab[i]->cycle)
			free(philo_tab[i]->cycle);
		if (philo_tab && philo_tab[i] && philo_tab[i]->name_death)
			free(philo_tab[i]->name_death);
		if (philo_tab && philo_tab[i])
			free(philo_tab[i]);
		i++;
	}
	if (philo_tab)
		free(philo_tab);
	return (0);
}

int	destroy_philo(t_philo **philo_tab, t_params *params, int nb_philo)
{
	destroy_semaphores(philo_tab, params, nb_philo);
	if (params)
		free(params);
	kill_philos(philo_tab, nb_philo);
	return (0);
}
