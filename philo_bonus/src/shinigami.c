/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinigami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:45:44 by christopher       #+#    #+#             */
/*   Updated: 2022/09/20 16:13:39 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	set_death(t_philo *philo, int id)
{
	philo->death = 1;
	printf("%ld %d %s\n", get_time() - philo->init_time, id, DIE);
	return (1);
}

int	check_death_each(t_philo *philo, t_params *params,
						int id, t_shinigami shini)
{
	int	ret;

	ret = 0;
	sc_sem_wait(philo->s_cycle);
	if (philo->cycle_time + shini.time_to_die < get_time())
	{
		sc_sem_wait(params->s_speak);
		sc_sem_wait(philo->s_death);
		ret = philo->death;
		if (!ret)
			ret = set_death(philo, id);
		else
		{
			sc_sem_post(philo->s_death);
			sc_sem_post(params->s_speak);
			sc_sem_post(philo->s_cycle);
			return (1);
		}
		sc_sem_post(philo->s_death);
		activate_snowden(params, shini.nb_philo);
		sc_sem_post(params->s_speak);
	}
	sc_sem_post(philo->s_cycle);
	return (ret);
}

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
		if (check_death_each(shini.philo, shini.philo->params, \
shini.philo->print_id, shini))
			break ;
		usleep(3000);
	}
	return (NULL);
}
