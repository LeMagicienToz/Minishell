/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:55 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 14:59:05 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_lexer	*create_node_lexer(char *str, int type)
{
	t_lexer		*node;
	static int	i = 0;

	node = malloc(sizeof(t_lexer));
	node->content = ft_strdup(str);
	node->index = i++;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addback_lexer(t_lexer *node, t_lexer **lst)
{
	t_lexer	*tmp;

	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	create_token_lexer(t_lexer **lst, char *str, int type)
{
	t_lexer	*node;

	if ((*lst) == NULL)
		(*lst) = create_node_lexer(str, type);
	else
	{
		node = create_node_lexer(str, type);
		addback_lexer(node, lst);
	}
}
