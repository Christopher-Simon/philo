/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:29:08 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:53:09 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	find_nb_size(t_flags *flag, long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		flag->neg++;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

int	find_prec(t_flags *flag, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			flag->prec = ft_atoi(&s[i + 1]);
			if (flag->prec == 0)
			{
				flag->prec = 1;
				return (0);
			}
			return (flag->prec);
		}
		i++;
	}
	flag->prec = 0;
	return (flag->prec);
}

int	find_width(t_flags *flag, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			break ;
		if (ft_isdigit(s[i]) && s[i] != '0')
		{
			flag->width = ft_atoi(&s[i]);
			return (flag->width);
		}
		i++;
	}
	flag->width = 0;
	return (flag->width);
}

int	find_hash(t_flags *flag, const char *s)
{
	(void)flag;
	if (ft_strchr(s, '#'))
		return (2);
	return (0);
}

int	find_zero(t_flags *flag, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && s[i] != '0')
			break ;
		if (s[i] == '0')
		{
			flag->zero = 1;
			return (flag->width);
		}
		i++;
	}
	flag->zero = 0;
	return (flag->width);
}
