/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:34:30 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/26 14:51:04 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	**file_retrieval_service(char **file, int fd, int number_of_lines)
{
	int	i;

	i = 0;
	while (i < number_of_lines)
	{
		file[i] = get_next_line(fd);
		if (file[i] == NULL)
		{
			close(fd);
			free_incomplete_array(file, i);
			error_msg_and_exit(MALLOC_FAIL, "@ file[i]", NULL);
		}
		i++;
	}
	file[i] = NULL;
	close(fd);
	return (file);
}

static char	**retrieve_file(char *av, int number_of_lines)
{
	char	**file;
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
	file = file_retrieval_service(file, fd, number_of_lines);
	return (file);
}

static int	count_lines_in_file(char *av)
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
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
