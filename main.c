/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:00:47 by mmarcott          #+#    #+#             */
/*   Updated: 2022/12/15 23:25:29 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*c;
	int		i;

	i = 0;
	fd = open("empty.txt", O_RDONLY);
	c = get_next_line(fd);
	while (c != NULL)
	{
		//if (c == NULL)
		//break ;
		printf("%s\n", c);
		c = ft_free(c);
		c = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
