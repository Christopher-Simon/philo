/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_flag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:32:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	prec(t_flags *flag, int x, char *r)
{
	int	i;

	if (flag->minus)
		i = x;
	else
		i = flag->prec;
	if (flag->minus && (flag->space || flag->plus))
		i--;
	x--;
	i--;
	while (r[x] == ' ')
	{
		x--;
		i--;
	}
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

static void	plus(int x, char *r)
{
	x--;
	while (r[x] == ' ')
		x--;
	while (x >= 0)
	{
		if (r[x] == ' ')
		{
			r[x] = '+';
			break ;
		}
		x--;
	}
}

static void	neg(int x, char *r)
{
	x--;
	while (r[x] == ' ')
		x--;
	while (x >= 0)
	{
		if (r[x] == ' ')
		{
			r[x] = '-';
			break ;
		}
		x--;
	}
}

static void	zero(t_flags *flag, int x, char *r)
{
	int	i;

	i = flag->width;
	if (flag->neg || flag->plus || flag->space)
		i--;
	while (r[x] == ' ')
		x--;
	while (x >= 0 && i >= 0)
	{
		if (r[x] == ' ')
			r[x] = '0';
		x--;
		i--;
	}
}

char	*i_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else
		i_minus(flag, x, r, str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->neg)
		neg(x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	if (flag->plus && !flag->neg)
		plus(x, r);
	free(str);
	return (r);
}
