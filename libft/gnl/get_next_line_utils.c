/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:48:52 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/20 11:25:58 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void	fn_tmp_strjoin(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*fn_strjoin(char *s1, char *s2)
{
	char	*str;
	int		str_1_len;
	int		str_2_len;

	if (!s1)
		str_1_len = 0;
	else
		str_1_len = fn_strlen(s1);
	if (!s2)
		str_2_len = 0;
	else
		str_2_len = fn_strlen(s2);
	str = malloc(str_1_len + str_2_len + 1);
	if (!str)
		return (0);
	fn_tmp_strjoin(str, s1, s2);
	return (str);
}

int	fn_str_index(const char *s, int character)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == character)
			return (i);
		i++;
	}
	return (-1);
}

size_t	fn_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*resize_str(char *str)
{
	char	*tmp_str;

	tmp_str = malloc(fn_strlen(str) + 1);
	if (!tmp_str)
	{
		free(str);
		return (NULL);
	}
	fn_tmp_strjoin(tmp_str, str, "");
	free(str);
	return (tmp_str);
}
