/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:19:06 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/25 08:36:13 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_for_nl(char *stash, char *buffer)
{
	int	i;
	int	k;
	int	b;

	b = 0;
	k = 0;
	i = 0;
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
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	joined = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

void	ezero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		s[i++] = 0;
}
