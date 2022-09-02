/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:23:53 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:53:21 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	long_int_size(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*long_fill(unsigned long int nb, int neg, char *str, int i)
{
	while (i-- > (0 + neg))
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_long(long int n)
{
	int					i;
	char				*str;
	unsigned long int	nb;
	int					neg;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		neg = 1;
	}
	else
		neg = 0;
	i = long_int_size(nb) + neg;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	long_fill(nb, neg, str, i);
	str[i] = '\0';
	return (str);
}
