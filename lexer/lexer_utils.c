/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:27:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/26 15:42:52 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_2str(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		printf("%s\n", str[j]);
		j++;
	}
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
		printf("export[%d] | out[%d] | in[%d] | [%d] - (%s)\n", tmp->export, tmp->fdout, tmp->fdin, tmp->index, tmp->content);
		tmp = tmp->next;
	}
	ft_printf_fd(1, "[PRINT-LST]\n");
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
