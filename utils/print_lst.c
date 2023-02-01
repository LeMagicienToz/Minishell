/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:52 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/31 17:02:32 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_lexer(t_lexer	*lexer)
{
	t_lexer	*tmp;

	tmp = lexer;
	ft_printf_fd(1, "[PRINT-LEXER]\n");
	while (tmp)
	{
		ft_printf_fd(1, "[%d] - (%s)\n", tmp->type, tmp->content);
		tmp = tmp->next;
	}
	ft_printf_fd(1, "[PRINT-LEXER]\n");
}

void	print_lst(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	ft_printf_fd(1, "[PRINT-LST]\n");
	while (tmp)
	{
		printf(" out[%d] | in[%d] | [%d] - (%s)\n", tmp->fdout, tmp->fdin, tmp->index, tmp->content);
		tmp = tmp->next;
	}
	ft_printf_fd(1, "[PRINT-LST]\n");
}
