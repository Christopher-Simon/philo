/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/13 22:46:33 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	end_forks(int *id, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		waitpid(id[i], NULL, 0);
		i++;
	}
	return (0);
}

int	error_fork(void)
{
	printf("FAILED FORK\n");
	//PAR LE SEMAPHORE DE DEATH
	return (0);
}

int	hitman_philo(int *id, int nb_philo)
{
	int	i;

	i = 0;
	sleep(3);
	while (i < nb_philo)
	{
		kill(id[i], 2);
		i++;
	}
	return (0);
}

int	create_fork(t_philo **philo_tab, t_params *params, int nb_philo)
{
	int	*id;
	int	i;

	i = 0;
	id = ft_calloc(nb_philo, sizeof(int));
	if (!id)
		return (1);
	while (i < nb_philo)
	{
		id[i] = fork();
		if (id[i] == -1)
			error_fork();
		if (id[i] == 0)
		{
			routine(philo_tab[i], params);
			break ;
		}
		i++;
	}
	if (id != 0)
	{
		// hitman_philo(id, nb_philo);
		end_forks(id, nb_philo);
	}
	free(id);
	remove_semaphores(philo_tab, nb_philo);
	return (0);
}
