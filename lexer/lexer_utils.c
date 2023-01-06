/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:27:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 21:32:37 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_lst(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	ft_printf_fd(1, "\n[PRINT-LST]\n");
	while (tmp)
	{
		ft_printf_fd(1, "[%d] - (%s)\n", tmp->index, tmp->content);
		tmp = tmp->next;
	}
	ft_printf_fd(1, "[PRINT-LST]\n\n");
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
