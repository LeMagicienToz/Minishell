/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:26:23 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 20:32:57 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_separator(char c)
{
	if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	else if (c == SPACECODE)
		return (SPACECODE);
	else if (c == HYPHENCODE)
		return (HYPHENCODE);
	else
		return (-1);
}

int	check_redirection(char *str, int i, t_data *data)
{
	if (str[i] == OUT)
	{
		data->in = fill_in(str, i);
		data->out = fill_out(str, i);
		return (OUT);
	}
	else
		return (-1);
}

int	check_pipe_lexer(char **lexer, t_data *data)
{
	static int	x;
	int			i;
	int			j;

	j = 0;
	x = 0;
	i = 0;
	while (lexer[i])
	{
		while (lexer[i][j])
		{
			if (lexer[i][j++] == PIPE)
				x++;
			else
				x = 0;
			if (x == 2)
			{
				data->errorlexer = "syntax error near unexpected token `|'";
				return (1);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_no_space(char *str, int i, t_data *data)
{
	if (str[i] == SPACECODE)
	{
		data->errorlexer = "syntax error";
		return (SPACECODE);
	}
	else
		return (0);
}
