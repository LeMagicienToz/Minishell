/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:30:13 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/27 17:07:31 by rperrin          ###   ########.fr       */
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
			res = fill_quote(&tmp, res);
		else if (tmp->type == QUOTE)
			res = fill_simple_quote(&tmp, res);
		else if (tmp->type == DOLLAR && tmp->next)
			res = fill_dollar(&tmp, res);
		else if (tmp->type == ROUT || tmp->type == DBROUT)
			fill_rout(&tmp, data);
		else if (tmp->type == RIN || tmp->type == DBRIN)
			fill_rin(&tmp, data);
		else if (tmp->type == EQUAL && tmp->prev && tmp->prev->type == TEXT)
			res = fill_export(&tmp, data, res);
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

char	*fill_quote(t_lexer **lexer, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	tmp = NULL;
	lex = (*lexer);
	if (lex->type == DBQUOTE)
	{
		lex = lex->next;
		while (lex && lex->type != DBQUOTE)
		{
			if (lex->type == DOLLAR && lex->next->type != DBQUOTE)
				res = fill_dollar(&lex, res);
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
	if (lex->type == QUOTE)
	{
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
	}
	(*lexer) = lex;
	return (res);
}

char	*fill_dollar(t_lexer **lexer, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	lex = (*lexer);
	tmp = NULL;
	if (lex->next->type == DOLLAR)
	{
		lex = lex->next;
		if (!res)
			res = ft_itoa(getpid());
		else
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, ft_itoa(getpid()));
			free(tmp);
		}
	}
	else if (lex->next->type == TEXT)
	{
		lex = lex->next;
		if (!res)
			res = getenv(lex->content);
		else if (lex->type == TEXT && getenv(lex->content))
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, getenv(lex->content));
			free(tmp);
		}
	}
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

void	fill_rout(t_lexer **lexer, t_data *data)
{
	char	*tmp;
	t_lexer	*lex;
	char	*res;
	int		ok;

	lex = (*lexer);
	ok = lex->type;
	tmp = NULL;
	res = NULL;
	if (lex->next)
		lex = lex->next;
	while (lex->type == SPACE && lex->next)
		lex = lex->next;
	if (lex->type == DBQUOTE)
		res = fill_quote(&lex, res);
	else if (lex->type == QUOTE)
		res = fill_simple_quote(&lex, res);
	else if (lex->type == DOLLAR && lex->next)
		res = fill_dollar(&lex, res);
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
		lex = lex->next;
	}
	if (res)
	{
		data->typeout = ok;
		data->out = open(res, O_CREAT | S_IRWXU);
	}
	(*lexer) = lex;
}

void	fill_rin(t_lexer **lexer, t_data *data)
{
	char	*tmp;
	t_lexer	*lex;
	char	*res;

	tmp = NULL;
	lex = (*lexer);
	res = NULL;
	if (lex->next)
		lex = lex->next;
	while (lex->type == SPACE && lex->next)
		lex = lex->next;
	if (lex->type == DBQUOTE)
		res = fill_quote(&lex, res);
	else if (lex->type == QUOTE)
		res = fill_simple_quote(&lex, res);
	else if (lex->type == DOLLAR && lex->next)
		res = fill_dollar(&lex, res);
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
		lex = lex->next;
	}
	if (res)
		data->in = open(res, O_RDONLY);
	(*lexer) = lex;
}

char	*fill_export(t_lexer **lexer, t_data *data, char *res)
{
	char	*tmp;
	t_lexer	*lex;

	tmp = NULL;
	lex = (*lexer);
	if (lex->next)
	{
		lex = lex->next;
		if (lex->type == DBQUOTE)
			res = fill_quote(&lex, res);
		else if (lex->type == QUOTE)
			res = fill_simple_quote(&lex, res);
		else if (lex->type == DOLLAR && lex->next)
			res = fill_dollar(&lex, res);
		else if (lex->type == TEXT || lex->type == EQUAL)
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
			lex = lex->next;
		}
	}
	if (res)
	{
		data->checkexport = 1;
		return (res);
	}
	else
		return (res);
	(*lexer) = lex;
}
