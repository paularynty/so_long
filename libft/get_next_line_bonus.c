/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:48:48 by prynty            #+#    #+#             */
/*   Updated: 2024/07/21 15:45:29 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	init(char **line, char **nl, char *buf, int fd)
{
	if (fd < 0 || fd >= OPEN_MAX)
		return (0);
	*line = malloc(1);
	if (*line == NULL)
		return (0);
	**line = '\0';
	*nl = ft_strchr(buf, '\n');
	return (1);
}

static int	read_to_buf(int fd, char *buf, char **line)
{
	ssize_t	bytes_read;

	gnl_bzero(buf, BUFFER_SIZE + 1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*line);
		return (-1);
	}
	if (bytes_read == 0)
	{
		if (**line == '\0')
		{
			free(*line);
			return (-1);
		}
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*nl;
	int			read_result;

	if (init(&line, &nl, buf[fd], fd) == 0)
		return (NULL);
	while (!nl)
	{
		line = gnl_strjoin(line, buf[fd], gnl_strlen(buf[fd]));
		if (!line)
			return (NULL);
		read_result = read_to_buf(fd, buf[fd], &line);
		if (read_result == -1)
			return (NULL);
		if (read_result == 0)
			return (line);
		nl = ft_strchr(buf[fd], '\n');
	}
	line = gnl_strjoin(line, buf[fd], (nl - buf[fd]) + 1);
	if (!line)
		return (NULL);
	gnl_copy(buf[fd], nl + 1);
	return (line);
}
