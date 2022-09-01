/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:28:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/08/04 15:20:17 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_buf(int fd, char *buf, char *line, size_t *n)
{
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret <= 0 && line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	else if (ret == 0 && line)
	{
		(*n)++;
		return (NULL);
	}
	buf[ret] = '\0';
	return (buf);
}

char	*sep_line(char **memory, char *line, int fd)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	memory[fd] = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!memory[fd])
	{
		free (line);
		return (NULL);
	}
	if (gnl_strchr(line, '\n'))
	{
		ft_strlcpy(memory[fd], &line[i + 1], ft_strlen(line) - i + 1);
		line[i + 1] = '\0';
	}
	return (line);
}

char	*memory_check(char **memory, char *line, int fd)
{
	line = gnl_strjoin(line, memory[fd]);
	free(memory[fd]);
	memory[fd] = NULL;
	return (line);
}

int	gnl_nagic(int fd, char **memory)
{
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		free_fd(memory);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		n;
	static char	*memory[1024];

	if (!gnl_nagic(fd, memory))
		return (NULL);
	n = 0;
	line = gnl_calloc(sizeof(char), 1);
	if (memory[fd])
		line = memory_check(memory, line, fd);
	if (gnl_strchr(line, '\n'))
		n++;
	while (n == 0)
	{
		if (!get_buf(fd, buf, line, &n) && !n)
			return (NULL);
		if (n)
			return (line);
		n = gnl_strchr(buf, '\n');
		line = gnl_strjoin(line, buf);
	}
	sep_line(memory, line, fd);
	return (line);
}
