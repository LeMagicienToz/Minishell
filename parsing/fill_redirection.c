/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:57:33 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 03:16:36 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*fill_rout_norm(t_lexer **lexer, t_data *data, char *res, char *tmp)
{
	t_lexer	*lex;

	lex = (*lexer);
	if (lex->type == DBQUOTE)
		res = fill_quote(&lex, data, res);
	else if (lex->type == QUOTE)
		res = fill_simple_quote(&lex, res);
	else if (lex->type == DOLLAR && lex->next)
		res = fill_dollar(&lex, data, res);
	else if (lex->type == TEXT)
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

void	fill_rout_end(t_data *data, char *res)
{
	if (data->typeout == 412)
			data->out = open(res, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	else if (data->typeout == 413)
	{
		data->out = open(res, O_CREAT | O_WRONLY | O_APPEND, 0600);
		if (data->out == -1)
			data->out = open(res, O_CREAT | O_WRONLY | O_APPEND, 0600);
	}
}

void	fill_rout(t_lexer **lexer, t_data *data)
{
	char	*tmp;
	t_lexer	*lex;
	char	*res;

	lex = (*lexer);
	tmp = NULL;
	res = NULL;
	data->typeout = lex->type;
	if (lex->next)
		lex = lex->next;
	while (lex && (lex->type != PIPE && lex->type != DBRIN \
	&& lex->type != RIN && lex->type != ROUT && lex->type != DBROUT))
	{
		res = fill_rout_norm(&lex, data, res, tmp);
		lex = lex->next;
	}
	if (res)
		fill_rout_end(data, res);
	free(res);
	if (lex)
		lex = lex->prev;
	(*lexer) = lex;
}
