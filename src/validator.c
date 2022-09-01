/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:00:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/01 19:00:46 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	overflow_check(long int a)
{
	if (a < -2147483648 || a > 2147483647)
		return (1);
	return (0);
}

int	has_alpha(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_each_arg(char *arg)
{
	if (ft_strlen(arg) == 0 || ft_strlen(arg) > 10)
		return (1);
	if (has_alpha(arg))
		return (1);
	if (overflow_check(ft_atol(arg)))
		return (1);
	if (ft_atol(arg) <= 0)
		return (1);
	return (0);
}

int	validator(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_each_arg(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
