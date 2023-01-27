/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:17:07 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/27 16:08:59 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_lst(t_lst **lst)
{
	t_lst	*next;
	t_lst	*tmp;

	// printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lst);
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_lex(t_lexer **lex)
{
	t_lexer	*next;
	t_lexer	*tmp;

	// printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lex);
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_data(t_data *data)
{
	// printf("%s:%d\n", __FILE__, __LINE__);
	data->maxindex = 0;
	data->checkexport = 0;
	if (data->input)
		free(data->input);
}

void	free_all(t_data *data, t_lexer **lex, t_lst **lst)
{
	// if (data->errorlexer)
	// {
	// 	free(data->errorlexer);
	// 	data->errorlexer = NULL;
	// }
	// else
	// {
		if (data != NULL)
			free_data(data);
		if (lst != NULL)
			free_lst(lst);
		if (lex != NULL)
			free_lex(lex);
	// }
}
