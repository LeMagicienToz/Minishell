/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:07:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 21:42:00 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_lst	*create_node(t_data *data, char *str)
{
	t_lst		*node;

	node = malloc(sizeof(t_lst));
	node->content = ft_strdup(str);
	node->index = data->maxindex;
	if (data->pipe == PIPE)
		data->maxindex++;
	node->in = data->in;
	node->out = data->out;
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
	int		i;

	data->maxindex = x;
	i = 0;
	if ((*lst) == NULL)
		(*lst) = create_node(data, str);
	else
	{
		node = create_node(data, str);
		addback(node, lst);
	}
}
