/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:16:49 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/25 08:06:38 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*currentread;
	char		*buffer;
	int			bytes;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	currentread = malloc(BUFFER_SIZE * sizeof(char));
	printf("\n---------------\nValue of stash: %s\n---------------\n\n", stash);
	if (stash)
	{
		printf("Stashing....");
		buffer = ft_strjoin((const char *)buffer, (const char *)stash);
		ezero(stash);
	}
	while (bytes > 0)
	{
		bytes = read(fd, currentread, BUFFER_SIZE);
		buffer = ft_strjoin((const char *)buffer, (const char *)currentread);
		if (check_for_nl(stash, buffer))
			return (check_for_nl(stash, buffer));
	}
	return (NULL);
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
		//free(c);
		i++;
	}
	close(fd);
	return (0);
}
