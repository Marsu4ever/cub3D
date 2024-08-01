/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:55 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:51:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	*su;

	i = 0;
	s = (char *)str;
	su = (char *)sub;
	if (su[0] == '\0')
		return (s);
	if (n == 0)
		return (0);
	while (s[i] != '\0' && i < n)
	{
		j = 0;
		while (s[i + j] == su[j] && i + j < n
			&& s[i + j] != '\0' && su[j] != '\0')
		{
			if (su[j + 1] == '\0')
				return (s + i);
			j++;
		}
		i++;
	}
	return (0);
}
