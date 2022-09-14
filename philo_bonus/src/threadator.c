/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:26:40 by christopher       #+#    #+#             */
/*   Updated: 2022/09/14 14:35:22 by christopher      ###   ########.fr       */
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
	{
		printf("First get_time failed, stopping here\n");
		return (1);
	}
	params->init_time = start_time + 500;
	while (i < nb_philo)
	{
		philo[i]->init_time = params->init_time;
		philo[i]->cycle_time = philo[i]->init_time;
		philo[i]->sh_cycle_time = philo[i]->init_time;
		i++;
	}
	return (0);
}

int	threadator(t_philo **philo_tab, t_params *params, int nb_philo)
{
	pthread_t	*th_philo;
	t_shinigami	shini;

	shini.time_to_die = params->time_to_die;
	shini.nb_philo = params->nb_philo;
	if (set_time_philo(philo_tab, nb_philo, params))
		return (1);
	th_philo = malloc(sizeof(pthread_t) * nb_philo);
	if (!th_philo)
		return (1);
	if (create_thread(philo_tab, th_philo, nb_philo))
		return (free(th_philo), 1);
	shinigami(philo_tab, params, shini);
	end_philo_thread(nb_philo, th_philo);
	return (0);
}
