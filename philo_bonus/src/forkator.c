/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:26:40 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 14:25:20 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	set_time_philo(t_philo **philo, int nb_philo, t_params *params)
{
	int		i;
	time_t	start_time;

	i = 0;
	start_time = get_time();
	if (start_time == -1)
		return (1);
	params->init_time = start_time + START_DELAY;
	while (i < nb_philo)
	{
		philo[i]->init_time = params->init_time;
		philo[i]->cycle_time = philo[i]->init_time;
		philo[i]->sh_cycle_time = philo[i]->init_time;
		i++;
	}
	return (0);
}

int	forkator(t_philo **philo_tab, t_params *params, int nb_philo)
{
	t_shinigami	shini;

	(void)shini;
	shini.time_to_die = params->time_to_die;
	shini.nb_philo = params->nb_philo;
	if (set_time_philo(philo_tab, nb_philo, params))
		return (1);
	if (create_fork(philo_tab, params, nb_philo))
		return (1);
	// shinigami(philo_tab, params, shini);
	return (0);
}
