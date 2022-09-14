/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:03:17 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/13 22:42:09 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	del_sem(const char *name)
{
	sem_t	*semaphore;

	printf("%s\n", name);
	semaphore = sem_open(name, 0);
	if (semaphore)
	{
		sc_sem_unlink(name);
		sc_sem_close(semaphore);
	}
	return (0);
}

int	remove_semaphores(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while(i < nb_philo)
	{
		del_sem(philo_tab[i]->cycle);
		i++;
	}
	del_sem(FORK);
	del_sem(SPEAK);
	return (0);
}

int	open_semaphores(t_philo **philo_tab, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo_tab[i]->s_cycle = sc_sem_open(philo_tab[i]->cycle, O_CREAT, 0755, nb_philo);
		if (!philo_tab[i]->s_cycle)
		{
			while (--i > 0)
			{
				sc_sem_unlink(philo_tab[i]->cycle);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	init_semaphore(t_philo **philo_tab, t_params *params, int nb_philo)
{
	printf("Il y a %d forks\n", nb_philo);
	// remove_semaphores(philo_tab, nb_philo);
	if (open_semaphores(philo_tab, nb_philo))
		return (1);
	params->s_fork = sc_sem_open(FORK, O_CREAT, 0755, nb_philo);
	if (!params->s_fork)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	params->s_speak = sc_sem_open(SPEAK, O_CREAT, 0755, 1);
	if (!params->s_speak)
		return (remove_semaphores(philo_tab, nb_philo), 1);
	return (0);
}
