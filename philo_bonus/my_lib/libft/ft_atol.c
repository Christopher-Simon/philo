/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:32 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/01 18:46:01 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	atol_while(const char *nptr, int i, long int a)
{
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		a = a * 10 + (nptr[i] - 48);
		i++;
	}
	return (a);
}

long int	ft_atol(const char *nptr)
{
	long int	a;
	int			i;
	int			neg;

	i = 0;
	a = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] == '0' && nptr[i + 1] != '\0')
		i++;
	a = atol_while(nptr, i, a);
	a *= neg;
	return (a);
}

//penser a checker le long avant et les overflow après

// int	overflow_check(long int a)
// {
// 	if (a < -2147483648 || a > 2147483647)
// 		return (1);
// 	return (0);
// }

// int	long_check(const char *nptr)
// {
// 	if (ft_strlen(nptr) > 12)
// 		return(1);
// 	return (0);
// }