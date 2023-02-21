/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:52:04 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 19:29:16 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*fill_quote(t_lexer **lexer, t_data *data, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	tmp = NULL;
	lex = (*lexer);
	lex = lex->next;
	while (lex && lex->type != DBQUOTE)
	{
		if (lex->type == DOLLAR && lex->next->type != DBQUOTE)
			res = fill_dollar(&lex, data, res);
		else if (res && lex->content && lex->type != DBQUOTE)
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, lex->content);
			free(tmp);
		}
		else if (lex->type != DBQUOTE)
			res = ft_strdup(lex->content);
		if (lex && lex->type != DBQUOTE)
			lex = lex->next;
	}
	(*lexer) = lex;
	return (res);
}

char	*fill_simple_quote(t_lexer **lexer, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	tmp = NULL;
	lex = (*lexer);
	lex = lex->next;
	while (lex && lex->type != QUOTE)
	{
		if (res && lex->content && lex->type != QUOTE)
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, lex->content);
			free(tmp);
		}
		else if (lex->type != QUOTE)
			res = ft_strdup(lex->content);
		if (lex && lex->type != QUOTE)
			lex = lex->next;
	}
	(*lexer) = lex;
	return (res);
}

char	*fill_dollar_normed(t_lexer **lexer, t_data *data, char *res, char *tmp)
{
	t_lexer	*lex;
	char	*lol;
	char	*leaks;

	leaks = NULL;
	lex = (*lexer);
	lex = lex->next;
	lol = ft_dollar_token(lex->content, data);
	if (!res)
		res = get_env(data, lol);
	else if (get_env(data, lol))
	{
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, get_env(data, lol));
		free(tmp);
	}
	if (data->dollartoken)
		res = fill_dollar_normdeouf(data, leaks, res);
	(*lexer) = lex;
	return (res);
}

char	*fill_dollar_norm(t_lexer **lexer, t_data *data, char *res, char *tmp)
{
	t_lexer	*lex;

	lex = (*lexer);
	lex = lex->next;
	if (!res)
		res = ft_itoa(data->status);
	else
	{
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, ft_itoa(data->status));
		free(tmp);
	}
	(*lexer) = lex;
	return (res);
}

char	*fill_dollar(t_lexer **lexer, t_data *data, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	lex = (*lexer);
	tmp = NULL;
	if (lex->next->type == TEXT && \
	ft_strlen(lex->next->content) == 1 && lex->next->content[0] == '?')
		res = fill_dollar_norm(&lex, data, res, tmp);
	else if (lex->next->type == TEXT)
		res = fill_dollar_normed(&lex, data, res, tmp);
	else
	{
		if (!res)
			res = ft_strdup(lex->content);
		else
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, lex->content);
			free(tmp);
		}
	}
	(*lexer) = lex;
	return (res);
}
