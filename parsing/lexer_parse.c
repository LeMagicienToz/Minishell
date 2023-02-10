/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/08 23:35:26 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_lst	*get_parsed(t_lexer	*lexer, t_data *data)
{
	t_lexer		*tmp;
	t_lst		*lst;
	char		*res;
	char		*join;

	tmp = lexer;
	res = NULL;
	lst = NULL;
	join = NULL;
	while (tmp)
	{
		data->stopn = 0;
		if (tmp->type == PIPE)
		{
			if (tmp->next)
			{
				tmp = tmp->next;
				create_token(data, &lst, res, data->x++);
				free(res);
				data->out = 0;
				data->in = 0;
				data->typeout = 0;
				data->hyphen = 0;
				data->n = -1;
				data->stopn = 0;
				data->null = 0;
				res = NULL;
			}
		}
		if ((tmp->type == DBQUOTE && tmp->next->type == DBQUOTE) \
		|| (tmp->type == QUOTE && tmp->next->type == QUOTE))
			data->null = 1;
		while (tmp && tmp->type == SPACE && res == NULL)
			tmp = tmp->next;
		while (tmp->type == SPACE && tmp->next && tmp->next->type == SPACE)
			tmp = tmp->next;
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
		{
			data->stopn = 1;
			data->null = 0;
			join = ft_strdup(res);
			free(res);
			res = ft_strjoin(join, tmp->content);
			free(join);
		}
		else
			res = ft_strdup(tmp->content);
		if (tmp)
			tmp = tmp->next;
	}
	if (res)
		create_token(data, &lst, res, data->x);
	return (lst);
}

// char	*if_pipe(t_lexer **lex, t_data *data, char *res)
// {
// 	if (tmp->next)
// 	{
// 		tmp = tmp->next;
// 		create_token(data, &lst, res, x++);
// 		free(res);
// 		data->out = 0;
// 		data->in = 0;
// 		data->typeout = 0;
// 		data->hyphen = 0;
// 		data->n = -1;
// 		data->stopn = 0;
// 		res = NULL;
// 	}
// 	return (res);
// }
