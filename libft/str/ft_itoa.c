/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:51:34 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_size(int n)
{
	int	num;

	num = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		num++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

static int	ft_step(int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (10);
	return (10 * ft_step(n - 1));
}

static void	ft_fillstr(char *str, int n)
{
	int	i;

	i = 0;
	while (i < ft_size(n))
	{
		str[i] = '0' + ((n / (ft_step(ft_size(n) - i - 1))) % 10);
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		temp;

	temp = n;
	str = malloc(ft_size(n) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (temp == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		i = 2;
		temp = 147483648;
	}
	if (temp < 0)
	{
		str[i] = '-';
		temp = -temp;
		i++;
	}
	ft_fillstr(str + i, temp);
	return (str);
}
