/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:19:06 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/28 22:06:02 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanup_stash(char **stash, char *line)
{
	int	i;
	int	k;

	k = ft_strlen(line);
	i = 0;
	while (stash && stash[0][k])
		stash[0][i++] = stash[0][k++];
	while (stash && stash[0][i])
		stash[0][i++] = 0;
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
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
	if (!s1 && !s2)
		return (NULL);
	joined = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!joined)
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (joined);
}

void	ft_free(void *p)
{
	if (p)
		free(p);
}

void	finalise(char **line, char **stash)
{
	put_line(line, *stash);
	cleanup_stash(stash, *line);
}
