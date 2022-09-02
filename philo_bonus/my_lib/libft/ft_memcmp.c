/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:53:05 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/30 11:40:58 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n--)
	{
		if ((*((unsigned char *)s1 + i)) != (*((unsigned char *)s2 + i)))
		{
			return ((*((unsigned char *)s1 + i))
				- (*((unsigned char *)s2 + i)));
		}
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
	
	char t1[] = "aaa";
	char t2[] = "aba";

	
	char at1[] = "5aa";
	char at2[] = "aba";


	char bt1[] = "0aa";
	char bt2[] = "aba";

	char ct1[] = "rtaa";
	char ct2[] = "ttba";

	int	s1[] = {10, 2, 3};
	int	s2[] = {1, 4, 3};

	//ft_print_memory(t1, sizeof(t1), sizeof(t1[0]));
	//ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	printf("memcmp --- %d, ft --- %d\n", memcmp(t1, t2, 
sizeof(t1)), ft_memcmp(t1, t2, sizeof(t1)));
	printf("memcmp --- %d, ft --- %d\n", memcmp(at1, at2, 
sizeof(at1)), ft_memcmp(at1, at2, sizeof(at1)));
	printf("memcmp --- %d, ft --- %d\n", memcmp(bt1, bt2, 
sizeof(bt1)), ft_memcmp(bt1, bt2, sizeof(bt1)));
	printf("memcmp --- %d, ft --- %d\n", memcmp(ct1, ct2, 
sizeof(ct1)), ft_memcmp(ct1, ct2, sizeof(ct1)));
	printf("memcmp --- %d, ft --- %d\n", memcmp(s1, s2, 
sizeof(s1)), ft_memcmp(s1, s2, sizeof(s1)));
}*/
