/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:16:25 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 16:02:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	count_word(char const *s, char c)
{
	int		i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			x++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (x);
}

int	split_free(char **split_tab, size_t x)
{
	if (!split_tab[x - 1])
	{
		while (x--)
			free(split_tab[x]);
		free(split_tab);
		return (1);
	}
	return (0);
}

char	**string(char const *s, char c, char **split_tab, size_t x)
{
	int	len;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			x++;
			len = 0;
			while (s[i] && s[i] != c)
			{
				len++;
				i++;
			}
			split_tab[x - 1] = malloc(sizeof(char) * (len + 1));
			if (split_free(split_tab, x))
				return (0);
		}
		if (s[i])
			i++;
	}
	return (split_tab);
}

char	**fill_string(char const *s, char c, char **split_tab)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			len = 0;
			while (s[i] && s[i] != c)
			{
				split_tab[count - 1][len] = s[i];
				len++;
				i++;
			}
			split_tab[count - 1][len] = '\0';
		}
		if (s[i])
			i++;
	}
	split_tab[count] = NULL;
	return (split_tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	**split_tab;

	if (!s)
		return (0);
	x = count_word(s, c);
	split_tab = malloc(sizeof(char *) * (x + 1));
	if (!split_tab)
		return (0);
	x = 0;
	string(s, c, split_tab, x);
	fill_string(s, c, split_tab);
	return (split_tab);
}
