/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:12:48 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:21:34 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*copy;

	copy = malloc(nmemb * size);
	if (!copy)
		return (0);
	ft_bzero(copy, nmemb * size);
	return (copy);
}
/*
#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strlen(char *str);
void	ft_print_memory(void *t, size_t n, size_t nb_bytes);


int	main(void)
{
	char 	s[] = "Hello world!";
	char	*s_copy;

	printf("%ld\n", sizeof(s));
	s_copy = (char *)calloc(ft_strlen(s),sizeof(char));
	if (s_copy == NULL)
		return (0);
	printf("%s\n", s_copy);
	ft_print_memory(s_copy, sizeof(s_copy), sizeof(s_copy[0]));
	ft_strlcpy(s_copy,s, sizeof(s));	
	ft_print_memory(s_copy, sizeof(s_copy), sizeof(s_copy[0]));
	printf("\n%s\n", s_copy);
	free(s_copy);
	printf("%ld\n", sizeof(s));
	
	s_copy = (char *)ft_calloc(ft_strlen(s),sizeof(char));
	if (s_copy == NULL)
		return (0);
	printf("\n%s\n", s_copy);
	ft_print_memory(s_copy, sizeof(s_copy), sizeof(s_copy[0]));
	ft_strlcpy(s_copy,s, sizeof(s));
	ft_print_memory(s_copy, sizeof(s_copy), sizeof(s_copy[0]));
	printf("%s\n", s_copy);
	free(s_copy);	
}*/
