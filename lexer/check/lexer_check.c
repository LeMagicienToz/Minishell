/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:26:23 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/02 18:41:57 by rperrin          ###   ########.fr       */
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
	int	error;

	if (!str)
		return (1);
	if (ft_str_is_space(str))
		return (1);
	else if (check_pipe_lexer(str, data))
		return (1);
	else if (check_quote(str, data))
		ft_printf_fd(1, "Erreur: %s\n", data->errorlexer);
	error = check_here_doc(str, data);
	if (error == 1)
		return (2);
	else if (error == 2)
		return (1);
	if (data->errorlexer)
		return (1);
	else
		return (0);
}
