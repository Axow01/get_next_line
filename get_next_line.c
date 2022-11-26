/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/26 04:15:16 by mmarcott         ###   ########.fr       */
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

	bytes = 1;
	if (!stash)
		init(&stash);
	if (read(fd, &buffer, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes > 0)
	{
		read_the_file(fd, &buffer, &bytes);
		stash = ft_strjoin((const char *)stash, (const char *)buffer);
		free(buffer);
		if (analyse(stash))
		{
			put_line(&line, stash);
			cleanup_stash(&stash, line);
			return (line);
		}
	}
	return (NULL);
}

void	read_the_file(int fd, char **buffer, int *bytes)
{
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*bytes = (int)read(fd, *buffer, BUFFER_SIZE);
	buffer[0][BUFFER_SIZE] = 0;
}

int	analyse(char *stash)
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
	line[0][i] = '\n';
	line[0][++i] = 0;
}

int	main(void)
{
	int		fd;
	char	*c;
	int		i;

	i = 0;
	fd = open("fichiertest", O_RDONLY);
	while (i < 10)
	{
		c = get_next_line(fd);
		printf("%s", c);
		free(c);
		i++;
	}
	close(fd);
	return (0);
}
