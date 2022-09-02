/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 11:53:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	argument2(char *s, va_list args, int x)
{
	t_flags	flag;

	if (ft_strchr(s, 'i'))
		x = flag_d(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'u'))
		x = flag_u(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'x'))
		x = flag_x(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'X'))
		x = flag_big_x(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, '%'))
	{
		ft_putchar_fd('%', 1);
		x = 1;
	}
	return (x);
}

int	argument(char *s, va_list args)
{
	int		x;
	t_flags	flag;

	x = 0;
	if (ft_strchr(s, 'c'))
		x = flag_c(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 's'))
		x = flag_s(flag, 0, s, va_arg(args, char *));
	if (ft_strchr(s, 'p'))
		x = flag_p(flag, 0, s, va_arg(args, unsigned long));
	if (ft_strchr(s, 'd'))
		x = flag_d(flag, 0, s, va_arg(args, int));
	x = argument2(s, args, x);
	return (x);
}

int	ft_printf3(int x, va_list args, char *s_flag)
{
	if (!check_flags(s_flag))
		x += argument(s_flag, args);
	else
		x += put_flag(s_flag);
	x--;
	return (x);
}

int	ft_printf2(const char *s, va_list args, int x, int i)
{
	char	*s_flag;
	int		mem;

	mem = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar_fd(s[i], 1);
		else
		{
			mem = ++i;
			while (s[i] && !ft_isalpha(s[i]) && s[i] != '%')
				i++;
			s_flag = ft_substr(s, mem, i - mem + 1);
			x = ft_printf3(x, args, s_flag);
			free(s_flag);
		}
		if (!s[i])
			return (x + 1);
		i++;
		x++;
	}
	return (x);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		x;

	x = 0;
	va_start(args, s);
	x = ft_printf2(s, args, 0, 0);
	va_end(args);
	return (x);
}
