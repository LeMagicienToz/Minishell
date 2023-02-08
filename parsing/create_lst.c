/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:07:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/08 20:51:44 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_lst	*create_node(t_data *data, char *str)
{
	t_lst		*node;

	node = malloc(sizeof(t_lst));
	node->content = ft_strdup(str);
	node->index = data->maxindex;
	node->fdin = data->in;
	node->fdout = data->out;
	node->typeout = data->typeout;
	node->n = data->n;
	node->null = data->null;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addback(t_lst *node, t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	create_token(t_data *data, t_lst **lst, char *str, int x)
{
	t_lst	*node;

	data->maxindex = x;
	if ((*lst) == NULL)
		(*lst) = create_node(data, str);
	else
	{
		node = create_node(data, str);
		addback(node, lst);
	}
}
