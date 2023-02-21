/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:27 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 15:43:06 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_token_normed(char c, char d)
{
	if (c == OUTCODE)
	{
		if (d && d == OUTCODE)
			return (DBROUT);
		else
			return (ROUT);
	}
	else if (c == INCODE)
	{
		if (d && d == INCODE)
			return (DBRIN);
		else
			return (RIN);
	}
	else
		return (0);
}

int	check_token(char c, char d)
{
	if (c == DBQUOTECODE)
		return (DBQUOTE);
	else if (c == QUOTECODE)
		return (QUOTE);
	else if (c == SPACECODE)
		return (SPACE);
	else if (c == PIPECODE)
		return (PIPE);
	else if (c == DOLLARCODE)
		return (DOLLAR);
	else if (c == HYPHENCODE)
		return (HYPHEN);
	else if (check_token_normed(c, d))
		return (check_token_normed(c, d));
	else
		return (TEXT);
}

char	*fill_token_lexer_normed(char *str, int *i, int type, char *ret)
{
	int	j;

	j = 0;
	if (type == TEXT)
	{
		while (str[*i] && type == TEXT)
		{
			ret[j++] = str[(*i)++];
			if (str[*i])
				type = check_token(str[*i], str[*i + 1]);
			else
				type = check_token(str[*i], (char)0);
		}
	}
	return (ret);
}

char	*fill_token_lexer(char *str, int *i, int type)
{
	int		j;
	char	*ret;

	j = 0;
	ret = malloc(sizeof(char) * get_len_token_lexer(str, *i, type) + 1);
	ret[get_len_token_lexer(str, *i, type)] = '\0';
	if (type == TEXT)
		ret = fill_token_lexer_normed(str, i, type, ret);
	else if (type == DBROUT)
	{
		while (str[*i] && str[*i] == OUTCODE)
			ret[j++] = str[(*i)++];
	}
	else if (type == DBRIN)
	{
		while (str[*i] && str[*i] == INCODE)
			ret[j++] = str[(*i)++];
	}
	else
		ret[j++] = str[(*i)++];
	return (ret);
}

t_lexer	*create_lexer(t_lexer *lex, char *str)
{
	int		i;
	int		type;
	char	*ret;

	i = 0;
	while (str[i])
	{
		type = check_token(str[i], str[i + 1]);
		ret = fill_token_lexer(str, &i, type);
		create_token_lexer(&lex, ret, type);
		free(ret);
	}
	return (lex);
}
