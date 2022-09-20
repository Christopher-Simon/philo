/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:14:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:25:25 by chsimon          ###   ########.fr       */
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

int	create_fork(t_philo **philo_tab, t_params *params, int nb_philo)
{
	int	*id;

	id = ft_calloc(nb_philo, sizeof(int));
	if (!id)
		return (1);
	create_fork2(philo_tab, params, nb_philo, id);
	free(id);
	remove_semaphores(philo_tab, nb_philo);
	return (0);
}
