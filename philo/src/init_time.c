/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:24:24 by christopher       #+#    #+#             */
/*   Updated: 2022/09/02 11:49:23 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include <limits.h>

time_t	get_time(void)
{
	struct timeval	get_time;

	if (sc_gettimeofday(&get_time, NULL))
		return (-1);
	return (get_time.tv_sec * 1000 + get_time.tv_usec / 1000);
}

time_t	get_elapsed_time(time_t time2, time_t time1)
{
	time_t	ret;

	ret = time2 - time1;
	return (ret);
}
