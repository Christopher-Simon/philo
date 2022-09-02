/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:08:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	i_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if ((flag->minus && (flag->space || flag->plus)) || flag->neg)
		x++;
	ft_strcpy(&r[x - flag->size], str, flag->size);
}

char	*get_i(t_flags *flag, int i)
{
	char	*str;
	char	*r;

	str = ft_itoa(i);
	if (flag->neg)
	{
		r = ft_substr(str, 1, flag->size);
		free(str);
	}
	else
		r = str;
	return (r);
}

int	flag_i(t_flags flag, int x, char *s, int i)
{
	char	*r;
	char	*str;

	get_flags(&flag, s);
	x = find_nb_size(&flag, i);
	flag.size = x - flag.neg;
	if (x < flag.prec)
		x = flag.prec + flag.neg;
	if (x < flag.width)
		x = flag.width;
	if ((flag.space || flag.plus) && (x == flag.size || x == flag.prec))
		x += 1 - flag.neg;
	str = get_i(&flag, i);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	i_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
