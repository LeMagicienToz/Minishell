/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:26:23 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/01 19:21:34 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_separator(char c)
{
	if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	else
		return (-1);
}

int	check_pipe_lexer(char *lexer, t_data *data)
{
	static int	x;
	int			i;

	x = 0;
	i = 0;
	while (lexer[i])
	{
		if (lexer[i] == PIPECODE)
			x++;
		else
			x = 0;
		if (x >= 2)
		{
			data->errorlexer = ft_strdup("syntax error \
			near unexpected token `|'");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_quote(char *str, t_data *data)
{
	int	i;
	int	x;
	int	last;

	i = 0;
	x = 0;
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			i++;
			while (str[i] != last && str[i])
				i++;
			if (str[i] != last)
				x = 1;
		}
		i++;
	}
	if (x == 1)
	{
		data->errorlexer = ft_strdup("QUOTE SANS FERMETURE");
		return (1);
	}
	return (0);
}

int	check_redirection(char c)
{
	if (c == OUTCODE)
		return (OUTCODE);
	else if (c == INCODE)
		return (INCODE);
	else if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	return (-1);
}

int	check_lexer_error(char *str, t_data *data)
{
	if (!str)
		return (1);
	if (ft_str_is_space(str))
		return (1);
	else if (check_pipe_lexer(str, data))
		ft_printf_fd(1, "Erreur: %s\n", data->errorlexer);
	else if (check_quote(str, data))
		ft_printf_fd(1, "Erreur: %s\n", data->errorlexer);
	if (data->errorlexer)
		return (1);
	else
		return (0);
}
