/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:29:55 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 21:38:22 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_len_token_spacecode(char *str, int i, char last, t_data *data)
{
	int	len;

	len = 0;
	while (str[i] == SPACECODE)
			i++;
	while (str[i] != last && str[i++])
	{
		if (check_redirection(str, i, data) != -1)
		{
			data->errorlexer = "syntax error near unexpected token `newline'";
			return (0);
		}
		len++;
	}
	return (len);
}

int	get_len_token_arg(char *str, int i, t_data *data)
{
	int	len;

	len = 0;
	while (ft_isprint(str[i]) && str[i])
	{
		if (check_no_space(str, i, data))
			return (0);
		len++;
		i++;
	}
	return (len);
}

int	get_len_token_quote(char *str, int i, char last)
{
	int	len;

	len = 0;
	while (str[i] != last && str[i++])
		len++;
	return (len);
}

int	get_len_token(char *str, int i, char last, t_data *data)
{
	int	len;

	len = 0;
	if (last == SPACECODE)
		len = get_len_token_spacecode(str, i, last, data);
	else if (last == HYPHENCODE)
		len = get_len_token_arg(str, i, data);
	else if (last == -1)
	{
		while (str[i])
		{
			last = check_separator(str[i++]);
			if (last == -1)
				len++;
			else
				break ;
		}
	}
	else
		len = get_len_token_quote(str, i, last);
	return (len);
}
