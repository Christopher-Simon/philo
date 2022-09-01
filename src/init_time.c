/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:24:24 by christopher       #+#    #+#             */
/*   Updated: 2022/08/27 19:01:22 by christopher      ###   ########.fr       */
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

	// printf("sec : %ld usec : %ld\n", get_time.tv_sec, get_time.tv_usec);
	// printf("sec : %ld usec : %ld\n", get_time.tv_sec * 1000, get_time.tv_usec / 1000);
	// printf("sec : %ld usec : %ld\n", get_time.tv_sec << 1, get_time.tv_usec >> 1);
	// printf("	%ld\n", LONG_MAX);
	// printf("	%lld\n", LLONG_MAX);
	// printf("sec : %ld\n", get_time.tv_sec * 1000 + get_time.tv_usec / 1000);
	// printf("sec : %ld\n", (get_time.tv_sec << 4) + (get_time.tv_usec >> 4));
	// printf("sec : %ld\n", get_time.tv_sec * 1000000 + get_time.tv_usec);

time_t	get_elapsed_time(time_t time2, time_t time1)
{
	time_t	ret;

	ret = time2 - time1;
	return (ret);	
}
