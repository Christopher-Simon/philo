/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:17:49 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 13:40:30 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "tripouille";
	char	c = 0;
	
	if (strchr(s,c) != NULL)
	{
		printf("%d\n",strchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
	if (ft_strchr(s,c) != NULL)
	{
		printf("%d\n",ft_strchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
}*/
