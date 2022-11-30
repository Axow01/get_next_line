/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mick <mick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/29 20:21:21 by mick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Lire n bytes du fichier fournis.
Mettre le buffer dans une variable stash.
Regarder si il y a un retour a la ligne.
Si oui:
1. Mettre la ligne jusqua $ dans la valeur line.
2. Clean up line dans stash.
3. Return line.
Si false: Recommencer en boucle.
*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			bytes;

	bytes = BUFFER_SIZE;
	line = NULL;
	buffer = NULL;
	if (read(fd, buffer, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_the_file(fd, &buffer, &bytes);
		stash = ft_strjoin((const char *)stash, (const char *)buffer);
		if (bytes == 0 && !ft_find(stash))
		{
			free(stash);
			return (NULL);
		}
		else if (ft_find(stash))
			return(finalise(&line, &stash), line);
		if (analyse(stash) || (!analyse(stash) && bytes < BUFFER_SIZE))
		{
			finalise(&line, &stash);
			return (line);
		}
	}
	return (NULL);
}

int	read_the_file(int fd, char **buffer, int *bytes)
{
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*bytes = read(fd, *buffer, BUFFER_SIZE);
	buffer[0][BUFFER_SIZE] = 0;
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
	*line = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	while (stash[i] && stash[i] != '\n')
	{
		line[0][i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[0][i++] = '\n';
	line[0][i] = 0;
}

int ft_find(char *stash)
{
	int i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == 0 || stash[i] == '\n')
			return (1);
		i++;
	}
	//if (bytes == 0 && i > 0)
		//return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			bytes;

	bytes = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_the_file(fd, &buffer, &bytes);
		stash = ft_strjoin(stash, buffer);
		if (!stash || (bytes <= 0 && !ft_find(stash)))
			return (stash = ft_free(stash) ,NULL);
		else if (ft_find(stash))
			return (finalise(&line, &stash), line);
		if (analyse(stash) || (!analyse(stash) && bytes < BUFFER_SIZE))
		{
			finalise(&line, &stash);
			return (line);
		}
	}
	return (NULL);
}
