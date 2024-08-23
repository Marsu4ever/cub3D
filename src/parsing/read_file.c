/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:34:30 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 11:29:41 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**retrieve_file(char *av, int number_of_lines)
{
	char	**file;
	int		i;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error_msg_and_exit(OPEN_FUNC_FAIL, strerror(errno), NULL);
	}
	file = malloc(sizeof(char *) * (number_of_lines + 1));
	if (file == NULL)
	{
		close(fd);
		error_msg_and_exit(MALLOC_FAIL, "@ retrieve_file", NULL);
	}
	i = 0;
	while (i < number_of_lines)
	{
		file[i] = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	return (file);
}

int	count_lines_in_file(char *av)
{
	int		i;
	int		fd;
	char	*line;
	int		line_count;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error_msg_and_exit(OPEN_FUNC_FAIL, strerror(errno), NULL);
	}
	line_count = 0;
	line = "let's get into the while loop!";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		line_count++;
	}
	close (fd);
	return (line_count);
}

void	read_file(t_vars *game, char *av)
{
	int	number_of_lines;

	number_of_lines = count_lines_in_file(av);
	game->file = retrieve_file(av, number_of_lines);
}
