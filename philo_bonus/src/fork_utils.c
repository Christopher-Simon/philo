/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/02 18:29:41 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	end_forks(int last_pid)
{
	waitpid(last_pid, NULL, 0);
	return (0);
}

int	error_fork(void)
{
	printf("FAILED FORK");
	//PAR LE SEMAPHORE DE DEATH
	return (0);
}

int	create_fork(t_philo **philo_tab, t_params *params, int nb_philo)
{
	int	id;
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		id = fork();
		if (id == -1)
			error_fork();
		if (id == 0)
		{
			routine(philo_tab[i], params);
			break ;
		}
		i++;
	}
	if (id != 0)
	{
		end_forks(id);
		remove_semaphores();
	}
	return (0);
}
