/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:48:22 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 21:15:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*s_join;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s_join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!s_join)
		return (0);
	ft_strlcpy(s_join, (char *)s1, (len1) + 1);
	ft_strlcpy(&s_join[len1], (char *)s2, len2 + 1);
	return (s_join);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "4z6qz1d0Hello.";
	char	s2[] = "world!qzdsqdxc";
	char	*s3;
	
	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	free(s3);
}*/
