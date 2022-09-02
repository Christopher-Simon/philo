/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_flag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:17:30 by chsimon           #+#    #+#             */
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
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

void	u_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	ft_strcpy(&r[x - flag->size], str, flag->size);
}

char	*u_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else
		u_minus(flag, x, r, str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	free(str);
	return (r);
}
