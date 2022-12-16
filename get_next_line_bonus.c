/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2022/12/16 14:55:55 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_the_file(int fd, char **buffer, ssize_t *bytes)
{
	*buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer[0])
	{
		*buffer = NULL;
		return (0);
	}
	*bytes = read(fd, *buffer, BUFFER_SIZE);
	return (1);
}

static int	analyse(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i++] == '\n')
			return (1);
	}
	return (0);
}

void	put_line(char **line, char *stash)
{
	int	i;

	i = 0;
	*line = ft_calloc((ft_strlen(stash) + 1), sizeof(char));
	if (!line[0])
	{
		*line = NULL;
		return ;
	}
	while (stash[i] && stash[i] != '\n')
	{
		line[0][i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[0][i++] = '\n';
}

int	ft_find(char *stash, ssize_t bytes)
{
	int	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == 0 || stash[i] == '\n')
			return (1);
		i++;
	}
	if ((bytes == 0 || bytes < BUFFER_SIZE) && i > 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;
	char		*buffer;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (stash[fd] = ft_free(stash[fd]), NULL);
	while (1)
	{
		read_the_file(fd, &buffer, &bytes);
		stash[fd] = ft_strjoin(stash[fd], buffer);
		if (!stash[fd] || bytes < 0)
			return (stash[fd] = ft_free(stash[fd]), NULL);
		if (analyse(stash[fd]) && ft_strlen(stash[fd]) > 0)
			return (finalise(&line, &stash[fd]), line);
		if (!stash[fd] || (bytes <= 0 && !ft_find(stash[fd], bytes)))
			return (stash[fd] = ft_free(stash[fd]), NULL);
		else if (ft_find(stash[fd], bytes))
			return (finalise(&line, &stash[fd]), stash[fd] = ft_free(stash[fd]),
				line);
		else if (bytes < BUFFER_SIZE)
			return (finalise(&line, &stash[fd]), stash[fd] = ft_free(stash[fd]),
				line);
	}
	return (stash[fd] = ft_free(stash[fd]), NULL);
}
