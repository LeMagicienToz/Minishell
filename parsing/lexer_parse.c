/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 19:27:22 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_parsed_pipe(t_lexer **lex, t_lst **listeu, t_data *data, char *res)
{
	t_lexer	*tmp;
	t_lst	*lst;

	lst = (*listeu);
	tmp = (*lex);
	if (tmp->next)
	{
		tmp = tmp->next;
		create_token(data, &lst, res);
		free(res);
		data->maxindex++;
		data->out = 0;
		data->in = 0;
		data->typeout = 0;
		data->hyphen = 0;
		data->n = -1;
		data->stopn = 0;
		data->null = 0;
		res = NULL;
	}
	(*listeu) = lst;
	(*lex) = tmp;
	return (res);
}

void	get_parsed_norm(t_lexer **lex, t_data *data, char *res)
{
	t_lexer	*tmp;

	tmp = (*lex);
	if ((tmp->type == DBQUOTE && tmp->next->type == DBQUOTE) \
	|| (tmp->type == QUOTE && tmp->next->type == QUOTE))
		data->null = 1;
	while (tmp && tmp->type == SPACE && res == NULL)
		tmp = tmp->next;
	(*lex) = tmp;
}

char	*get_parsed_normed_norm(t_lexer **lex, t_data *data, char *res)
{
	char	*join;
	t_lexer	*tmp;

	join = NULL;
	tmp = (*lex);
	data->stopn = 1;
	data->null = 0;
	join = ft_strdup(res);
	free(res);
	res = ft_strjoin(join, tmp->content);
	free(join);
	return (res);
}

char	*get_parsed_normed(t_lexer **lex, t_data *data, char *res)
{
	t_lexer	*tmp;

	tmp = (*lex);
	if (tmp->type == DBQUOTE)
		res = fill_quote(&tmp, data, res);
	else if (tmp->type == QUOTE)
		res = fill_simple_quote(&tmp, res);
	else if (tmp->type == DOLLAR && tmp->next)
		res = fill_dollar(&tmp, data, res);
	else if (tmp->type == ROUT || tmp->type == DBROUT)
		fill_rout(&tmp, data);
	else if (tmp->type == RIN || tmp->type == DBRIN)
		fill_rin(&tmp, data);
	else if (tmp->type == SPACE && tmp->next && tmp->next->type == HYPHEN \
	&& tmp->next->next && tmp->next->next->type == TEXT)
		res = fill_hyphen(&tmp, data, res);
	else if (res && tmp->content)
		res = get_parsed_normed_norm(&tmp, data, res);
	else
		res = ft_strdup(tmp->content);
	(*lex) = tmp;
	return (res);
}

t_lst	*get_parsed(t_lexer	*lexer, t_data *data)
{
	t_lexer		*tmp;
	t_lst		*lst;
	char		*res;

	tmp = lexer;
	res = NULL;
	lst = NULL;
	while (tmp)
	{
		if (tmp->type == PIPE)
			res = get_parsed_pipe(&tmp, &lst, data, res);
		get_parsed_norm(&tmp, data, res);
		res = get_parsed_normed(&tmp, data, res);
		if (tmp)
			tmp = tmp->next;
	}
	if (res)
		create_token(data, &lst, res);
	free (res);
	return (lst);
}
