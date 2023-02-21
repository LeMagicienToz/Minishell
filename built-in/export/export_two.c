/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:48:17 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 00:36:53 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_lst	*get_parsed_export(t_lexer *lexer, t_data *data)
{
	t_exp	exp;

	exp.res = NULL;
	exp.lst = NULL;
	exp.tmp = lexer;
	data->maxindex = 0;
	if (exp.tmp->next)
		exp.tmp = exp.tmp->next;
	else
		return (NULL);
	while (exp.tmp->type == SPACE)
		exp.tmp = exp.tmp->next;
	while (exp.tmp)
	{
		get_parsed_export_normed(data, lexer, &exp);
		if (exp.tmp)
			exp.tmp = exp.tmp->next;
	}
	if (exp.res)
		create_token(data, &exp.lst, exp.res);
	return (exp.lst);
}

void	ft_export_normed(t_data *data)
{
	t_lst	*lol;

	lol = get_parsed_export(data->lexer, data);
	while (lol)
	{
		if (data->str[1])
		{
			free(data->str[1]);
			data->str[1] = ft_strdup(lol->content);
		}
		if (data->str[1])
			check_equal(data);
		lol = lol->next;
	}	
}

void	ft_export(t_data *data, t_lst *lst)
{
	t_lst	*tmp;

	(void)lst;
	if (data->str[1] && data->maxindex == 0)
	{
		ft_export_normed(data);
	}
	else
	{
		tmp = data->export;
		if (lst->next)
			print_export_in_pipe(data, tmp);
		else
			print_export(data, tmp);
	}
}
