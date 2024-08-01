/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:52:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:52:09 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (i < src_length && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_length);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (i < n && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}
