/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:42:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/17 19:37:31 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_isprint(char c)
{
	if (c >= 33 && c <= 38)
		return (1);
	else if (c >= 43 && c <= 46)
		return (1);
	else if (c >= 48 && c <= 58)
		return (1);
	else if (c == 61)
		return (1);
	else if (c >= 63 && c <= 91)
		return (1);
	else if (c == 92)
		return (1);
	else if (c >= 93 && c <= 95)
		return (1);
	else if (c >= 97 && c <= 123)
		return (1);
	else if (c >= 125 && c <= 126)
		return (1);
	return (0);
}

int	check_out(char *str, int i, int last, t_data *data)
{
	int	x;

	x = 1;
	while (str[i] == SPACECODE)
		i++;
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			while (str[i] != last)
				if (str[i++] != SPACECODE)
					x = 0;
			i++;
		}
		else if (check_isprint(str[i++]))
			x = 0;
	}
	if (x == 1)
		data->errorlexer = ft_strdup("syntax error \
		near unexpected token `newline'");
	return (x);
}

int	check_double_out(char *str, int i, int last, t_data *data)
{
	int	x;

	x = 1;
	while (str[i] == SPACECODE)
		i++;
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			while (str[i] != last)
				if (str[i++] != SPACECODE)
					x = 0;
			i++;
		}
		else if (check_isprint(str[i++]))
			x = 0;
	}
	if (x == 1)
		data->errorlexer = ft_strdup("syntax error \
		near unexpected token `newline'");
	return (x);
}

int	check_redirection_lexer(char *str, t_data *data)
{
	int	i;
	int	last;

	i = 0;
	while (str[i])
	{
		last = check_redirection(str[i]);
		printf("(%c) %d\n", str[i], last);
		if (last == DBQUOTECODE || last == QUOTECODE)
		{
			i++;
			printf("IN2\n");
			while (str[i] != last)
				i++;
			i++;
		}
		else if (last == OUTCODE && str[i + 1] == OUTCODE)
		{
			if (check_double_out(str, i + 1, last, data))
				return (1);
		}
		else if (last == OUTCODE)
		{
			printf("IN\n");
			if (check_out(str, i, last, data))
				return (1);
		}
		i++;
	}
	return (0);
}
