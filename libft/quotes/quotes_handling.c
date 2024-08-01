/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:50:44 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/29 13:50:51 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/* 
   return_value = 0 if we have open quote and not closed!
   return_value = 1 when inside pair of quotes we have another one
   return_value = 2 when we have same quotes closed without other quote inside
   return_value = 3 if there are no quotes
*/

static int	return_value(char quote, int inside_quotes, int flag)
{
	if (quote != 0)
		return (0);
	else if (quote == 0 && inside_quotes == 1)
		return (1);
	else if (quote == 0 && inside_quotes == 0 && flag == 1)
		return (2);
	else
		return (3);
}

int	check_word(char *string, int start, int end)
{
	int		inside_quotes;
	char	quote;
	int		flag;

	inside_quotes = 0;
	quote = 0;
	flag = 0;
	while (start < end)
	{
		if (string[start] == '"' || string[start] == '\'')
		{
			flag = 1;
			if (quote == 0)
				quote = string[start];
			else if (quote == string[start])
				quote = 0;
			else
				inside_quotes = 1;
		}
		start++;
	}
	return (return_value(quote, inside_quotes, flag));
}

/*
   return_value = -1 open quotes and not closed
   return_value = 0 not inside quotes 
   return_value = 1 inside of double quotes with no quotes between
   return_value = 2 inside of single quotes with no quotes between
   return_value = 3 mix of different quotes
*/
int	is_inside_quotes(char *str, int start, int end)
{
	if (check_word(str, start, end) == 0)
		return (-1);
	if (check_word(str, start, end) == 3)
		return (0);
	if (str[start] == '"' && str[end - 1] == '"' \
		&& check_word(str, start + 1, end - 1) == 3)
		return (1);
	if (str[start] == '\'' && str[end - 1] == '\'' \
		&& check_word(str, start + 1, end - 1) == 3)
		return (2);
	return (3);
}

/*
checking if we have inside of one quotes different type of quotes, 
without any other type of mix

return_value = 0 if not inside of quotes
return_value = 1 if inside of single quotes
return_value = 2 if inside of double quotes
*/
int	inside_mix(char *str, int start, int end)
{
	char	quote;
	int		return_value;

	quote = 0;
	return_value = 0;
	if ((str[start] == '\'' || str[start] == '"') \
		&& is_inside_quotes(str, start, end) == 3)
	{
		quote = str[start];
		if (quote == '\'')
			return_value = 1;
		else
			return_value = 2;
		start++;
		while (str[start] != 0 && start < end)
		{
			if (str[start] == quote && start + 1 < end && str[start + 1] != 0)
				return (0);
			start++;
		}
	}
	return (return_value);
}
