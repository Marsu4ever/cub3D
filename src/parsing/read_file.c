/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:34:30 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/15 14:29:10 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**retrieve_config_file(char *av, int number_of_lines)
{
	char	**file;
	int		i;
	int 	fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error_msg_and_exit(OPEN_FUNC_FAIL, strerror(errno), NULL);
	}
	file = malloc(sizeof(char *) * (number_of_lines + 1));
	if (file == NULL)
	{
		close(fd);
		error_msg_and_exit(MALLOC_FAIL, "@ retrieve_config_file", NULL);
	}
	i = 0;
	// printf("retrieve whole file\n");
	while (i < number_of_lines)
	{
		file[i] = get_next_line(fd);
		// printf("i: %d\n", i);
		// if (file[i])
		// {
		// 	printf("%s\n",  file[i]);
		// }
		i++;
		// printf("%s\n", file[i]);
	}
	file[i] = NULL;
	return (file);	
}

int	count_lines_in_file(char *av)
{
	int		fd;
	char	*line;
	int		line_count;
	int i;

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
	// printf("line_count: %d\n", line_count);
	return (line_count);
}

void	read_file(t_vars *game, char *av)
{
	/*
		-open file
		
		-count lines
		-whole file - malloc
	*/

	int	number_of_lines;

	number_of_lines = count_lines_in_file(av);
	game->config_file = retrieve_config_file(av, number_of_lines);
	// print_it(game->config_file);
	/*
		-print whole map - function
	*/
	// if (fd == 0)
}
