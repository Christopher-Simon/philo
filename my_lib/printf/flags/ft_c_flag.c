/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:20:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:53:56 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*c_fillis(t_flags *flag, int x, char *r, int c)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (flag->width && !flag->minus)
		r[flag->width - 1] = c;
	else
		r[0] = c;
	return (r);
}

int	flag_c(t_flags flag, int x, char *s, int c)
{
	char	*r;
	int		i;

	x = 1;
	i = 0;
	get_flags(&flag, s);
	if (x < flag.width)
		x = flag.width;
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	c_fillis(&flag, x, r, c);
	while (i < x)
		ft_putchar_fd(r[i++], 1);
	free(r);
	return (x);
}
