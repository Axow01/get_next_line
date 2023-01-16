/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2023/01/16 16:30:59 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1- Read the file with the value of BUFFER_SIZE.
	2- Check the stash variable to see if there is a \n.
	3- If so then return the variable up to the \n.
	4- Else continue to read.
*/

#include "get_next_line_bonus.h"

int	ft_find(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	extract(char *str, char **line)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	*line = ft_calloc(i += 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[0][i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[0][++i] = '\n';
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;
	char		*buffer;
	ssize_t		bytes;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (stash[fd] = ft_free(stash[fd]), NULL);
	bytes = BUFFER_SIZE;
	stash[fd] = ft_calloc(1, sizeof(char));
	while (bytes == BUFFER_SIZE && !ft_find(stash[fd]))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes = read(fd, buffer, BUFFER_SIZE);
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	if (bytes <= 0 && ft_strlen(stash[fd]) > 0)
	{
		extract(stash[fd], &line);
		return (line);
	}
	else
		return (stash[fd] = ft_free(stash[fd]), NULL);
}

/*
int	main(void)
{
	char *line;

	line = get_next_line(open("file.txt", O_RDONLY));
	printf("%s", line);
	ft_free(line);
	return (0);
}*/