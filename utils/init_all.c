/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:40 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/26 17:24:30 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_data(t_data	*data)
{
	printf("%s:%d\n", __FILE__, __LINE__);
	data->maxindex = 0;
	data->export = 0;
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
