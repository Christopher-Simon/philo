/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:52:04 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/29 15:58:16 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long unsigned int	i;
	long unsigned int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	char	*big[] = { "Hello'\0' world!",  "Hello world!", "", "test" ,NULL};
	char	little[] = "world";

	int	i = 0;
//	printf("strnstr :%s\n",strnstr(big, little, sizeof(big)));
	while (big [i])
	{
		printf("ft_     :%s\n",ft_strnstr(big[i], little, sizeof(big)));
		i++;
	}
}*/
