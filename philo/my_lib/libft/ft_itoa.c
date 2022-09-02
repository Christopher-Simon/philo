/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:17:23 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:26:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	int_size(int n)
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

char	*fill(unsigned int nb, int neg, char *str, int i)
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

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nb;
	int				neg;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		neg = 1;
	}
	else
		neg = 0;
	i = int_size(nb) + neg;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	fill(nb, neg, str, i);
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	c[] = {0, -1, 1, -5, 5, -6, +6, -2147483648, 2147483647};
	int	i;

	i = 0;
	while (i < 9)
		printf("%s\n", ft_itoa(c[i++]));
}*/
