/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowden.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:05:48 by christopher       #+#    #+#             */
/*   Updated: 2022/09/14 18:03:43 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*snowden(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	(void)philo;
	sc_sem_wait(philo->params->s_nowden);
	sc_sem_wait(philo->s_death);
	philo->death = 1;
	sc_sem_post(philo->s_death);
	sem_post(philo->params->s_all);
	sc_sem_post(philo->params->s_nowden);
	return (NULL);
}
