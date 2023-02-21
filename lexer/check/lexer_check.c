/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:26:23 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/20 15:51:59 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_separator(char c)
{
	if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	else
		return (-1);
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
		data->status = 400;
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
	else if (check_quote(str, data))
		return (1);
	else if (check_pipe_lexer(str, data))
		return (1);
	else if (redirection_check(str, data))
		return (1);
	return (0);
}
