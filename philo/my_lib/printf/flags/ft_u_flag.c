/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:59:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*get_u(t_flags *flag, unsigned int d)
{
	char	*str;

	(void)flag;
	str = ft_itoa_long(d);
	return (str);
}

char	*flag_u_null(int x)
{
	char	*str;

	str = malloc(x + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, " ", 2);
	return (str);
}

int	magic_u(t_flags *flag, int x, unsigned int i)
{
	if (flag->null && flag->prec && flag->prec_size == 0)
		x = flag->prec_size;
	else
		x = find_nb_size(flag, i);
	flag->size = x;
	if (x < flag->prec && !flag->null)
		x = flag->prec;
	if (x < flag->width)
		x = flag->width;
	return (x);
}

int	flag_u(t_flags flag, int x, char *s, int d)
{
	unsigned int	i;
	char			*r;
	char			*str;

	get_flags(&flag, s);
	if (!d && flag.prec_size == 0)
		flag.null = 1;
	if (d < 0)
		i = 4294967296 + d;
	else
		i = d;
	x = magic_u(& flag, x, i);
	if (flag.null && flag.prec && flag.prec_size == 0)
		str = flag_u_null(1);
	else
		str = get_u(&flag, i);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	u_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
