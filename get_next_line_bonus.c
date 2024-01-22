/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:19:52 by hel-asli          #+#    #+#             */
/*   Updated: 2024/01/22 04:32:16 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_file(char *buffer, int fd)
{
	char	*str;
	int		n;

	if (!buffer)
		return (NULL);
	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	n = 0;
	while (!ft_strchr(buffer))
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n > 0)
		{
			str[n] = 0;
			buffer = ft_strjoin(buffer, str);
			if (!buffer)
				return (free(buffer), buffer = NULL, NULL);
		}
	}
	return (free(str), str = NULL, buffer);
}

char	*read_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_rest(char *buffer)
{
	int		i;
	char	*rest;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest = ft_strdup(&buffer[i]);
	free(buffer);
	buffer = NULL;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;	

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strdup("");
	buffer[fd] = read_from_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	if (!*buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = read_line(buffer[fd]);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = read_rest(buffer[fd]);
	if (!buffer[fd])
		return (free(line), line = NULL, NULL);
	return (line);
}
