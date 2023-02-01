/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/01 13:17:46 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_lst	*get_parsed(t_lexer	*lexer, t_data *data)
{
	t_lexer		*tmp;
	t_lst		*lst;
	char		*res;
	char		*join;
	static int	x;

	x = 0;
	tmp = lexer;
	res = NULL;
	lst = NULL;
	join = NULL;
	while (tmp && tmp->type == SPACE)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			if (tmp->next)
			{
				tmp = tmp->next;
				create_token(data, &lst, res, x++);
				free(res);
				res = NULL;
			}
		}
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
		else if (res && tmp->content)
		{
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
		create_token(data, &lst, res, x++);
	return (lst);
}
