/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*s_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - flag->size], str, flag->size);
	else
		ft_strcpy(r, str, flag->size);
	return (r);
}

char	*flag_s_null(t_flags *flag)
{
	char	*str;

	if (flag->prec && flag->prec_size < 6)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * (6 + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, "(null)", 7);
	}
	return (str);
}

int	flag_s(t_flags flag, int x, char *s, char *str)
{
	char	*r;

	get_flags(&flag, s);
	if (!str)
		flag.null = 1;
	if (!flag.null)
	{
		if (flag.prec && ((int)ft_strlen(str) >= flag.prec_size))
			str = ft_substr(str, 0, flag.prec_size);
	}
	else
		str = flag_s_null(&flag);
	x = ft_strlen(str);
	flag.size = x;
	if (x < flag.width)
		x = flag.width;
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	s_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	if ((flag.prec && (flag.size == flag.prec_size)) || flag.null)
		free(str);
	return (x);
}
