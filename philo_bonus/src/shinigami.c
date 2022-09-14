/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinigami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:45:44 by christopher       #+#    #+#             */
/*   Updated: 2022/09/13 22:38:34 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_death_each(t_philo *philo, t_params *params,
	int id, t_shinigami shini)
{
	int	ret;

	ret = 0;
	sc_sem_wait(philo->s_cycle);
	if (philo->cycle_time + shini.time_to_die < get_time())
	{
		sc_sem_wait(params->s_speak);
		ret = philo->death;
		if (!ret)
		{
			philo->death = 1;
			ret = 1;
			printf("%ld %d %s\n", get_time() - philo->init_time, id, DIE);
		}
		// usleep(100000);
		sc_sem_post(params->s_speak);
	}
	sc_sem_post(philo->s_cycle);
	return (ret);
}

// int	check_stop(t_params *params, int nb_philo)
// {
// 	int	ret;

// 	ret = 0;
// 	if (params->stop == nb_philo)
// 	{
// 		params->death = 1;
// 		ret = 1;
// 	}
// 	return (ret);
// }

void	*shinigami(void *arg)
{
	t_shinigami	shini;

	shini = *(t_shinigami *)arg;
	if (DB_HADES)
	{
		printf("IN SHINIGAMI ");
		print_philo(shini.philo);
		printf("\n\n");
	}
	while (1)
	{
		if (check_death_each(shini.philo, shini.philo->params, shini.philo->print_id,shini))
		{
			// || check_stop(params, shini.nb_philo))
			break ;
		}
		usleep(3000);
	}
	return (NULL);
}

int	init_shinigami(t_philo *philo)
{
	t_shinigami	shini;
	pthread_t	th_shinigami;

	shini.philo = philo;
	shini.time_to_die = philo->time_to_die;
	shini.nb_philo = philo->nb_philo;
	if (sc_pthread_create(&th_shinigami, NULL, shinigami, &shini))
		return (1); //PROCEDURE ARRET DES AUTRES Philo
	return (0);
}
