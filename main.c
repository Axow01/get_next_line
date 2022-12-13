/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:00:47 by mmarcott          #+#    #+#             */
/*   Updated: 2022/12/12 18:54:34 by mmarcott         ###   ########.fr       */
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
	while (i < 10)
	{
		c = get_next_line(fd);
		//if (c == NULL)
			//break ;
		printf("%s", c);
		free(c);
		i++;
	}
	close(fd);
	return (0);
}
