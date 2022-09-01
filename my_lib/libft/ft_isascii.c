/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:01:58 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 11:26:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>



int	main(int ac, char **av)
{
	if (ac != 2)
		printf("C'est pas le bon nombre d'argument salaud.");
	printf("is ascii ? %d\n", isascii(atoi(av[1])));
	printf("is ft_ascii ? %d", ft_isascii(atoi(av[1])));
}*/
