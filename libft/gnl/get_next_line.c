/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:48:48 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/20 11:26:12 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void	shift_buff(char *buff, size_t from)
{
	int		i;

	i = 0;
	while (buff[from + i] != 0)
	{
		buff[i] = buff[from + i];
		i++;
	}
	buff[i] = 0;
}

char	*get_next_line_concat(char **str, char *buff)
{
	char	*tmp_str;

	tmp_str = fn_strjoin(*str, buff);
	free(*str);
	if (!tmp_str)
		return (NULL);
	*str = fn_strjoin("", tmp_str);
	free(tmp_str);
	if (!*str)
		return (NULL);
	return (*str);
}

char	*get_next_line_init(char **str, int fd, char *buff, int *line_size)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	*line_size = 0;
	*str = fn_strjoin("", buff);
	if (!str)
		return (NULL);
	return (*str);
}

char	*next_line_parse(int line_size, int new_line, char *buff, char **str)
{
	if (new_line != -1)
	{
		shift_buff(buff, fn_str_index(buff, '\n') + 1);
		*(*str + new_line + 1) = 0;
	}
	else
		buff[0] = 0;
	if (line_size == -1)
	{
		free(*str);
		return (NULL);
	}
	if (line_size == 0 && fn_strlen(*str) == 0)
	{
		free(*str);
		return (NULL);
	}
	return (resize_str(*str));
}

char	*get_next_line(int fd)
{
	char				*str;
	int					line_size;
	int					new_line;
	static char			buff[BUFFER_SIZE + 1];

	if (!get_next_line_init(&str, fd, buff, &line_size))
		return (NULL);
	new_line = fn_str_index(str, '\n');
	while (new_line == -1)
	{
		line_size = read(fd, buff, BUFFER_SIZE);
		if (line_size <= 0)
			break ;
		buff[line_size] = 0;
		if (!get_next_line_concat(&str, buff))
			return (NULL);
		new_line = fn_str_index(str, '\n');
	}
	return (next_line_parse(line_size, new_line, buff, &str));
}
