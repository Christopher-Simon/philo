/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:54:07 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/01 19:55:12 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	end_philo_thread(int nb, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (sc_pthread_join(thread[i], NULL))
			return (1);
		i++;
	}
	free(thread);
	return (0);
}

int	create_thread(t_philo **philo_tab, pthread_t *thread, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (sc_pthread_create(&thread[i], NULL, &routine, philo_tab[i]))
		{
			while (--i >= 0)
				sc_pthread_join(thread[i], NULL);
			return (1);
		}
		i++;
	}
	return (0);
}
