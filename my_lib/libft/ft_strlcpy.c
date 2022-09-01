/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:23:30 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:27:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	src[] = "coucou";
	char	dest[10] = "AAAAAAAAA";
	char	dest2[10] = "AAAAAAAAA";

	printf("%ld\n", ft_strlcpy(dest, src, -1));
	printf("%ld\n", strlcpy(dest2, src, -1));
	printf("%s\n", dest);	
	printf("%s\n", &dest[strlen(src) + 1]);	
	printf("%s\n", dest2);	
	printf("%s\n", &dest2[strlen(src) + 1]);	
}*/
