/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:20:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:20:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_params	*get_params(char **argv)
{
	t_params	*params;

	params = ft_calloc(sizeof(t_params), 1);
	if (!params)
		return (NULL);
	params->fork = ft_atoi(argv[1]);
	params->nb_philo = params->fork;
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->round = ft_atoi(argv[5]);
	else
		params->round = -1;
	return (params);
}
