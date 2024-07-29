/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:51:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_numofstr(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static char	*ft_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(finish - start + 1);
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_splitstr(char **str, const char *s, char c, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	ns;

	i = 0;
	j = 0;
	while (i < num)
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			if (ft_strchr(s + j, c) == 0)
				ns = ft_strlen(s + j);
			else
				ns = ft_strchr(s + j, c) - (s + j);
			str[i] = ft_word(s, j, j + ns);
			i++;
			j += ns;
		}
	}
	str[i] = NULL;
}

static int	ft_checkmem(char **str, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (str[i] == 0)
		{
			while (num > 0)
			{
				free(str[num - 1]);
				num--;
			}
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		num;

	if (!s)
		return (0);
	num = ft_numofstr(s, c);
	str = (char **)malloc(sizeof(char *) * (num + 1));
	if (!str || !s)
		return (NULL);
	ft_splitstr(str, s, c, num);
	if (ft_checkmem(str, num) == 0)
		return (NULL);
	return (str);
}
