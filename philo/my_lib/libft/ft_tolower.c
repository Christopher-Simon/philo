/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:00:09 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:25:58 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	str[] = "HeLlo world!";
	int	i;	

	i = 0;
	printf("%s\n", str);
	while(str[i])
		printf("%c", tolower(str[i++]));
	i = 0;
	printf("\n");
	while(str[i])
		printf("%c", ft_tolower(str[i++]));
}*/
