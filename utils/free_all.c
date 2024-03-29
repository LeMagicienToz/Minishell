/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:17:07 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 15:34:32 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_lst(t_lst **lst)
{
	t_lst	*next;
	t_lst	*tmp;

	tmp = (*lst);
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	free_lex(t_lexer **lex)
{
	t_lexer	*next;
	t_lexer	*tmp;

	tmp = (*lex);
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lex = NULL;
}

void	free_data(t_data *data)
{
	data->maxindex = 0;
	data->checkexport = 0;
	data->out = 0;
	data->in = 0;
	data->typeout = 0;
	data->stopn = 0;
	data->n = -1;
	data->null = 0;
	free(data->input);
	data->input = NULL;
}

void	free_all(t_data *data, t_lexer **lex, t_lst **lst)
{
	if (data->envi)
		free_data_str(&data->envi);
	if (data != NULL)
		free_data(data);
	if (lst != NULL)
		free_lst(lst);
	if (lex != NULL)
		free_lex(lex);
}
