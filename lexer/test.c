/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:31:58 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/27 17:08:13 by rperrin          ###   ########.fr       */
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
	else if (c == EQUALCODE)
		return (EQUAL);
	else if (check_token_normed(c, d))
		return (check_token_normed(c, d));
	else
		return (TEXT);
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

char	*fill_token_lexer_normed(char *str, int *i, int type, char *ret)
{
	int	j;

	j = 0;
	if (type == TEXT)
	{
		while (str[*i] && type == TEXT)
		{
			ret[j++] = str[(*i)++];
			type = check_token(str[*i], str[*i + 1]);
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
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		type = check_token(str[i], str[i + 1]);
		ret = fill_token_lexer(str, &i, type);
		create_token_lexer(&lex, ret, type);
		free(ret);
	}
	print_lexer(lex);
	return (lex);
}

void	print_lexer(t_lexer	*lexer)
{
	t_lexer	*tmp;

	tmp = lexer;
	ft_printf_fd(1, "[PRINT-LEXER]\n");
	while (tmp)
	{
		ft_printf_fd(1, "[%d] - (%s)\n", tmp->type, tmp->content);
		tmp = tmp->next;
	}
	ft_printf_fd(1, "[PRINT-LEXER]\n");
}
