/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:42:59 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/29 22:53:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char *)s + i++) = '\0';
}
/*
#include <strings.h>
#include <string.h>
#include <stdio.h>

void    ft_print_memory(void *t, size_t n, size_t nb_bytes);
int	main(void)
{
	int	t[] = {0, 1 , 2, 3};
	int	t2[] = {0, 1 , 2, 3};
	int	c = 7;
	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	bzero(t, c);
	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	printf("\n----mon bzero----\n");
	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	ft_bzero(t2, c);
	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
}*/
