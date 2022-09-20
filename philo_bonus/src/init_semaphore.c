/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:03:17 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 15:51:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	del_sem(const char *name)
{
	sem_t	*semaphore;

	semaphore = sem_open(name, 0);
	if (semaphore)
	{
		sem_unlink(name);
		sc_sem_close(semaphore);
	}
	return (0);
}

int	remove_semaphores(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		del_sem(philo_tab[i]->cycle);
		del_sem(philo_tab[i]->name_death);
		i++;
	}
	del_sem(FORK);
	del_sem(SPEAK);
	del_sem(SNOWDEN);
	del_sem(ALL);
	del_sem(ROUND);
	del_sem(END);
	del_sem(P_END);
	return (0);
}

int	open_semaphores(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo_tab[i]->s_death = sc_sem_open(philo_tab[i]->name_death,
				O_CREAT, 0755, 1);
		if (!philo_tab[i]->s_death)
			return (1);
		philo_tab[i]->s_cycle = sc_sem_open(philo_tab[i]->cycle,
				O_CREAT, 0755, 1);
		if (!philo_tab[i]->s_cycle)
			return (1);
		i++;
	}
	return (0);
}

int	init_semaphore(t_philo **philo_tab, t_params *params, int nb_philo)
{
	remove_semaphores(philo_tab, nb_philo);
	if (open_semaphores(philo_tab, nb_philo))
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_fork = sc_sem_open(FORK, O_CREAT, 0755, nb_philo);
	if (!params->s_fork)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_speak = sc_sem_open(SPEAK, O_CREAT, 0755, 1);
	if (!params->s_speak)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_nowden = sc_sem_open(SNOWDEN, O_CREAT, 0755, 0);
	if (!params->s_nowden)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_all = sc_sem_open(ALL, O_CREAT, 0755, 0);
	if (!params->s_all)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_round = sc_sem_open(ROUND, O_CREAT, 0755, 0);
	if (!params->s_round)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_end = sc_sem_open(END, O_CREAT, 0755, 0);
	if (!params->s_end)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_p_end = sc_sem_open(P_END, O_CREAT, 0755, 1);
	if (!params->s_p_end)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	return (0);
}
