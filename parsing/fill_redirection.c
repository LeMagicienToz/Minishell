/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:57:33 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/10 20:09:35 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	fill_rin(t_lexer **lexer, t_data *data)
{
	char	*tmp;
	t_lexer	*lex;
	char	*res;

	tmp = NULL;
	lex = (*lexer);
	res = NULL;
	data->typeout = lex->type;
	if (lex->next)
		lex = lex->next;
	while (lex->type == SPACE && lex->next)
		lex = lex->next;
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
	if (res)
	{
		if (data->typeout == 415)
			here_doc(res, data);
		else
			data->in = open(res, O_RDONLY);
	}
	(*lexer) = lex;
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
	while (lex->type == SPACE && lex->next)
		lex = lex->next;
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
	if (res)
	{
		if (data->typeout == 412)
		{
			data->out = open(res, O_APPEND);
			if (data->out != -1)
				remove(res);
			data->out = open(res, O_RDWR | O_CREAT, S_IRUSR + \
			S_IWUSR + S_IRGRP + S_IROTH);
		}
		else if (data->typeout == 413)
		{
			data->out = open(res, O_APPEND);
			if (data->out == -1)
				data->out = open(res, O_RDWR | O_CREAT, S_IRUSR + \
				S_IWUSR + S_IRGRP + S_IROTH);
		}
	}
	(*lexer) = lex;
}
