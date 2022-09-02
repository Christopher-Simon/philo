/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:14:45 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/26 15:06:53 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc((ft_strlen((char *)s) + 1) * sizeof(const char));
	if (!copy)
		return (0);
	ft_strlcpy(copy, (char *)s, ft_strlen((char *)s) + 1);
	return (copy);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "Hello world!";
	char *cpy;

	cpy = ft_strdup(src);
	printf("%s\n", cpy);
	free(cpy);
	
	printf("%s\n", cpy);
	cpy = strdup(src);
	printf("%s\n", cpy);
	free(cpy);
}*/
