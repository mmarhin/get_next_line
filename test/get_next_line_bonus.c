/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 08:35:41 by mamarin-          #+#    #+#             */
/*   Updated: 2025/07/03 18:58:27 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++] || !buffer[i])
		return (free(buffer), NULL);
	leftover = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!leftover)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		leftover[j++] = buffer[i++];
	leftover[j] = '\0';
	free(buffer);
	return (leftover);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	char	*new_buffer;
	ssize_t	read_bytes;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp || !buffer)
		return (free(buffer), free(tmp), NULL);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(tmp), free(buffer), NULL);
		tmp[read_bytes] = '\0';
		new_buffer = ft_strjoin(buffer, tmp);
		if (!new_buffer)
			return (free(tmp), NULL);
		buffer = new_buffer;
	}
	free(tmp);
	return (buffer);
}

static void	ft_cleanup(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd] || !buffer[fd][0])
		return (ft_cleanup(&buffer[fd]), NULL);
	line = ft_line(buffer[fd]);
	if (!line)
		return (ft_cleanup(&buffer[fd]), NULL);
	temp_buffer = buffer[fd];
	buffer[fd] = ft_next_line(temp_buffer);
	return (line);
}
