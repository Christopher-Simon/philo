/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinigami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:45:44 by christopher       #+#    #+#             */
/*   Updated: 2022/09/01 16:12:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_death_each(t_philo *philo, t_params *params, int id, t_shinigami shini)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(philo->cycle);
	if (philo->cycle_time + shini.time_to_die < get_time())
	{
		pthread_mutex_lock(&params->m_death);
		ret = params->death;
		if (!ret)
		{
			params->death = 1;
			ret = 1;
			printf("%ld %d %s\n", get_time() - philo->init_time, id, DIE);
		}
		pthread_mutex_unlock(&params->m_death);
	}
	pthread_mutex_unlock(philo->cycle);
	return (ret);
}

int	check_death(t_philo **philo, t_params *params, t_shinigami shini)
{
	int	i;

	i = 0;
	while (i < shini.nb_philo)
	{
		if (check_death_each(philo[i], params, i + 1, shini))
			return (1);
		i++;
	}
	return (0);
}

int	check_stop(t_params *params, int nb_philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&params->m_stop);
	if (params->stop == nb_philo)
	{
		pthread_mutex_lock(&params->m_death);
		params->death = 1;
		pthread_mutex_unlock(&params->m_death);	
		ret = 1;
	}
	pthread_mutex_unlock(&params->m_stop);
	return (ret);
}

int	shinigami(t_philo **philo, t_params *params, t_shinigami shini)
{
	if (DB_HADES)
	{
		pthread_mutex_lock(&params->m_death);
		printf("IN SHINIGAMI ");
		print_all_philo(philo, shini.nb_philo);
		printf("\n\n");
		pthread_mutex_unlock(&params->m_death);	
	}
	while (1)
	{
		if (check_death(philo, params, shini) || check_stop(params, shini.nb_philo))
			break;
		usleep(3000);
	}
	return (0);
}
