/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:32:02 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/26 17:47:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_putnbr_base(char *str, unsigned long int n, char *base, int count)
{
	unsigned int	div;
	unsigned int	mod;
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

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size_malloc(unsigned int div, unsigned int base_len, int i)
{
	while (div >= base_len)
	{
		div = div / base_len;
		i++;
	}
	return (i);
}

char	*to_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	char			*str;
	int				i;
	unsigned int	n;

	i = 1;
	base_len = ft_strlen(base);
	n = nbr;
	i = size_malloc(n, base_len, i);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	ft_putnbr_base(str, n, base, i - 1);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	a;
	char			*str;

	if (check_base(base_from) == 0)
		return (0);
	if (check_base(base_to) == 0)
		return (0);
	a = ft_atoi_base(nbr, base_from);
	free(nbr);
	str = to_base(a, base_to);
	return (str);
}
