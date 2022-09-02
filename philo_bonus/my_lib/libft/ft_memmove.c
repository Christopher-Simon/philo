/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:02:53 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 10:18:48 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (*(unsigned char *)&dest < *(unsigned char *)&src)
	{
		while (n--)
		{
			*((unsigned char *)dest + i) = *((unsigned char *) src + i);
			i++;
		}
	}
	else
		while (n--)
			*((unsigned char *) dest + n) = *((unsigned char *)src + n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	char	t[] = "";
	char	t2[] = "";
	char	*dest;
	char	*dest2;
	int		n = 0;
	int		c = 1;
	
	dest = t + 1;
	dest2 = t2 + 1;
	printf("memmove\n");
	memmove(((void*)0), ((void*)0), 5);
//	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	printf("%s\n", dest);

	printf("\nft_memmove\n");
	printf("\n%s\n", dest2);
	ft_memmove(((void*)0), ((void*)0), 5);
//	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	printf("\n%s\n", dest2);
}*/
