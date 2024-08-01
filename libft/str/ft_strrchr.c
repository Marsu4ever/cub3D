/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:51 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:51:53 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	*cur;
	int		len;

	s = (char *)str;
	len = ft_strlen(s);
	cur = s + len;
	while (*cur != (unsigned char)c)
	{
		if (cur == s)
			return (NULL);
		cur--;
	}
	return (cur);
}
