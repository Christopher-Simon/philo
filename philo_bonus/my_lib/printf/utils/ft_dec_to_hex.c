/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:46:53 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:53:25 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static char	*ft_putnbr_base(char *str, unsigned long n, char *base, int count)
{
	unsigned long	div;
	unsigned long	mod;
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	div = n / i;
	mod = n % i;
	if (div != 0)
		ft_putnbr_base(str, div, base, count - 1);
	str[count] = base[mod];
	return (str);
}

static int	size_malloc(unsigned long div, unsigned int base_len, int i)
{
	while (div >= base_len)
	{
		div = div / base_len;
		i++;
	}
	return (i);
}

static char	*to_base(unsigned long nbr, char *base)
{
	unsigned int		base_len;
	char				*str;
	int					i;
	unsigned long int	n;

	i = 1;
	base_len = 16;
	n = nbr;
	i = size_malloc(n, base_len, i);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	ft_putnbr_base(str, n, base, i - 1);
	return (str);
}

char	*ft_dec_to_hex(unsigned long i)
{
	char	*str;

	str = to_base((unsigned long)i, "0123456789abcdef");
	return (str);
}
