/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:17:29 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/28 22:06:03 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
int		read_the_file(int fd, char **buffer, int *bytes);
int		ft_strlen(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	put_buf_stash(char *stash, char *buffer);
int		analyse(char *stash);
void	put_line(char **line, char *stash);
void	cleanup_stash(char **stash, char *line);
void	ft_free(void *p);
void	finalise(char **line, char **stash);
int 	ft_find(char *stash);

#endif
