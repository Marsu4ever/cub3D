/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:51:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_char_to_int(char c)
{
	return ((int)(c - '0'));
}

int	ft_atoi(const char *str)
{
	int		minus;
	long	number;

	minus = 1;
	number = 0;
	while (*str != '\0' && ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
		{
			number = -1 * ft_char_to_int(*(str + 1));
			minus = -1;
			str++;
		}
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		number = number * 10 + minus * ft_char_to_int(*str);
		if (number / minus < 0)
			return ((minus > 0) * (-1));
		str++;
	}
	return (number);
}

int	ft_atoi_short(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		return (-1);
	return (res);
}
