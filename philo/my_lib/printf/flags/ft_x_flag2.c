/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_flag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:24:08 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	prec(t_flags *flag, int x, char *r)
{
	int	i;

	if (!x)
		return ;
	if (flag->minus)
		i = x;
	else
		i = flag->prec;
	if (flag->minus && (flag->hash))
		i -= 2;
	x--;
	i--;
	while (r[x] == ' ' && x > 0)
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

static void	zero(t_flags *flag, int x, char *r)
{
	int	i;

	i = flag->width;
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

static void	hash(t_flags *flag, int x, char *r)
{
	if (flag->minus)
		x = flag->size;
	while (x--)
	{
		if (r[x] == ' ')
		{
			r[x] = 'x';
			r[x - 1] = '0';
			return ;
		}
	}
	r[1] = 'x';
	r[0] = '0';
}

void	x_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if (flag->hash)
		x += 2;
	ft_strcpy(&r[x - flag->size], str, flag->size);
}

char	*x_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else
		x_minus(flag, x, r, str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	if (flag->hash)
		hash(flag, x, r);
	free(str);
	return (r);
}
