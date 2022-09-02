/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:30:11 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:25:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	char_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1len;
	size_t	i;
	char	*trim;

	i = 0;
	if (!s1 || !set)
		return (0);
	s1len = ft_strlen((char *)s1) - 1;
	while (char_is_set(s1[i], set))
		i++;
	while (char_is_set(s1[s1len], set) && s1len)
		s1len--;
	trim = ft_substr((char *)s1, i, s1len - i + 1);
	return (trim);
}
/*
#include <stdio.h>
int	main(void)
{
	char s1[] = "          ";
	char	set[] = " ";
	
	char	*trim;
	
	trim = ft_strtrim(s1, set);
	printf("%s\n", trim);
}*/
