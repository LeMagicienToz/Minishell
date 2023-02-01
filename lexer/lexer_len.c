/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:29:55 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/30 18:07:07 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_len_token_lexer(char *str, int i, int type)
{
	int	len;

	len = 0;
	if (get_len_token_lexer_normed(str, i, type, len))
		return (get_len_token_lexer_normed(str, i, type, len));
	else if (type == DBROUT || type == DBRIN)
		len = 2;
	else
		len++;
	return (len);
}

int	get_len_token_lexer_normed(char *str, int i, int type, int len)
{
	if (type == TEXT)
	{
		while (str[i] && type == TEXT)
		{
			i++;
			len++;
			type = check_token(str[i], str[i + 1]);
		}
		return (len);
	}
	return (0);
}
