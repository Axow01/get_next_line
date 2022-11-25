/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/25 04:17:19 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*currentread;
	char		*buffer;
	int			bytes;
	int			i;
	int			k;
	int			b;

	i = 0;
	b = 0;
	bytes = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	currentread = malloc(BUFFER_SIZE * sizeof(char));
	printf("%s\n", stash);
	while (bytes != 0)
	{
		bytes = read(fd, currentread, BUFFER_SIZE);
		buffer = ft_strjoin((const char *)buffer, (const char *)currentread);
		while (buffer[i])
		{
			if (buffer[i++] == '\n')
			{
				stash = malloc(BUFFER_SIZE * sizeof(char));
				k += i;
				while (buffer[k])
					stash[b++] = buffer[k++];
				stash[b] = 0;
				buffer[i] = 0;
				return (buffer);
			}
		}
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("fichiertest", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
