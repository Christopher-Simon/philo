/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:15:29 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:25:16 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL || f == NULL)
		return (0);
	i = ft_strlen((char *)s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)s, i + 1);
	if (!str)
		return (0);
	while (i--)
		str[i] = f(i, str[i]);
	return (str);
}
/*
#include <unistd.h>

char	up(unsigned int i, char c)
{
	c += i;
	return (c);
}

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	ft_strlen(char *str);

int	main(int ac, char **av)
{
	char	s[] = "hello";

	if (ac != 2)
	{
		printf("pas le bon nombre d'argument");
		return (0);
	}
	printf("%s\n", ft_strmapi(av[1], &mapi));
}*/
