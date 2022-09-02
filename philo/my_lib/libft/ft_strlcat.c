/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:43:07 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/30 20:23:36 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	long unsigned int	j;
	size_t				len_src;
	size_t				len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	j = 0;
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	while (j < size - len_dst - 1 && src[j])
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = '\0';
	return (len_dst + len_src);
}
/*
#include <bsd/string.h>


int	main(void)
{
	char	src[] = "";
	char	dest[25] = "Hello";
	char	dest2[25] = "Hello";
	
	size_t	d;
	size_t d2;
	size_t i = 0;	


	d = strlcat(dest, src, i);
	d2 = ft_strlcat(dest2, src, i);
	if (d == d2)
		printf("OK____\n");	
	else
		printf("KO____\n");
	printf("strlcat : %ld --- ", d);
	printf("%ld ft_\n", d2);
	printf("dest : %s\n", dest);
	printf("dest2 : %s\n", dest2);
}*/
