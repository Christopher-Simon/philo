/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:12:50 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 21:00:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(sizeof(char), 1));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)&s[start], (len + 1));
	return (sub);
}
/*
#include <string.h>

int	main(void)
{
	char	str[] = "";
	char	*sub;

	sub = ft_substr(str, 100, 1);
//	if (strcmp(sub, "u"))
//		printf("c'est pareil\n");
//	else
//		printf("c'est pete\n");
	printf("%s\n", sub);	
	free(sub);
}*/
