/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mick <mick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:00:47 by mmarcott          #+#    #+#             */
/*   Updated: 2022/12/15 12:58:38 by mick             ###   ########.fr       */
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
		if (c == NULL)
			break ;
		printf("%s\n", c);
		c = ft_free(c);
		i++;
	}
	close(fd);
	return (0);
}
