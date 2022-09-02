/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:44:09 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/29 19:54:46 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if ((*(unsigned char *)&c) == *((unsigned char *)s + i))
			return ((void *)s + i);
		i++;
	}	
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);


int	main(void)
{
//	char t[] = "l";
//	char c = 'l';
//	size_t nb = 3;	
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	
	void *n = ft_memchr(tab, -1, 7);
	void *m = memchr(tab, -1, 7);
	(void)n;
	printf("%s\n", (char *)m);
	if (m)
		printf("byte exists\n");
	else 	
		printf("byte does not exist\n");
	if (n)
		printf("byte exists\n");
	else 	
		printf("byte does not exist\n");
	if (m == n)
		printf("OK");
	else
		printf("KO");
}*/
