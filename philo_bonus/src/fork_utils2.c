/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:24:37 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/26 13:25:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	error_fork(t_params *params)
{
	printf("FAILED FORK\n");
	sc_sem_wait(params->s_speak);
	usleep(15000);
	sc_sem_post(params->s_nowden);
	sc_sem_post(params->s_speak);
	return (0);
}

void	*round_end(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	sc_sem_wait(params->s_end);
	sc_sem_wait(params->s_p_end);
	params->end = 1;
	sc_sem_post(params->s_p_end);
	return (NULL);
}

void	failed_wait_rounds(t_params *params)
{
	printf("FAILED THREAD WAIT ROUNDS\n");
	sc_sem_wait(params->s_speak);
	usleep(15000);
	sc_sem_post(params->s_nowden);
	sc_sem_post(params->s_speak);
}

int	wait_rounds(t_params *params, int nb_philo)
{
	int			i;
	pthread_t	th_round_end;
	int			ret;

	if (sc_pthread_create(&th_round_end, NULL, round_end, params))
		return (failed_wait_rounds(params), 1);
	i = 0;
	ret = 0;
	while (i < nb_philo)
	{
		sc_sem_wait(params->s_round);
		i++;
	}
	sc_sem_wait(params->s_p_end);
	ret = params->end;
	sc_sem_post(params->s_p_end);
	if (!ret)
	{
		sc_sem_wait(params->s_speak);
		activate_snowden(params, nb_philo);
		sc_sem_post(params->s_speak);
	}
	sc_pthread_join(th_round_end, NULL);
	return (0);
}

void	create_fork2(t_philo **philo_tab, t_params *params,
					int nb_philo, int *id)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
	{
		id[i] = fork();
		if (id[i] == -1)
		{
			error_fork(params);
			break ;
		}
		if (id[i] == 0)
		{
			routine(philo_tab[i], params);
			break ;
		}
		if (i + 1 == nb_philo)
			break ;
	}
	if (id[i] != 0)
	{
		if (nb_philo != 1)
			wait_rounds(params, nb_philo);
		end_forks(id, nb_philo);
	}
}
