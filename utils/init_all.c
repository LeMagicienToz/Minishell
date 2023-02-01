/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:40 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/01 14:49:54 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_data(t_data *data, char **envp)
{
	data->envp = envp;
	data->exp = envp;
	data->maxindex = 0;
	data->status = 0;
	data->checkexport = 0;
	data->errorlexer = NULL;
}

void	init_lst(t_lst	**lst)
{
	t_lst	*tmp;

	printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lst);
	tmp = NULL;
}

void	init_lex(t_lexer	**lex)
{
	t_lexer	*tmp;

	printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lex);
	tmp = NULL;
}
