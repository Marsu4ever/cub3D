/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:49:05 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:49:07 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* get_next_line_utils.c */
char	*fn_strjoin(char *s1, char *s2);
int		fn_str_index(const char *s, int character);
size_t	fn_strlen(const char *s);
char	*resize_str(char *str);

/* get_next_line.c */
char	*get_next_line_concat(char **str, char *buff);
char	*get_next_line_init(char **str, int fd, char *buff, int *line_size);
char	*next_line_parse(int line_size, int new_line, char *buff, char **str);
char	*get_next_line(int fd);

#endif
