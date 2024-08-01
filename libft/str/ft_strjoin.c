/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:52:13 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:52:15 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
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
	return (str);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*temp;

	if (!s1 || !s2 || !s3)
		return (0);
	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (0);
	str = ft_strjoin(temp, s3);
	free(temp);
	if (!str)
		return (0);
	return (str);
}

char	*ft_strjoin_new(char **dst, char **src)
{
	char	*temp;

	if (!*dst)
		return (ft_strdup(*src));
	else if (!*src)
	{
		temp = ft_strdup(*dst);
		free (*dst);
		return (temp);
	}
	else
	{
		temp = ft_strjoin(*dst, *src);
		if (!temp)
			exit(EXIT_FAILURE);
		free(*dst);
		return (temp);
	}
}
