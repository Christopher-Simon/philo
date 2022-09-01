/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:52:50 by chsimon           #+#    #+#             */
/*   Updated: 2022/08/16 12:27:21 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	sc_gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz)
{
	if (gettimeofday(tv, tz) == -1)
	{
		perror("get_time_of_day"); //TODO TO REMOVE
		return (1);
	}
	return (0);
}