/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:08:10 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 20:45:27 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	unset_normed(t_lst *tmp, t_lst *next, t_lst *prev, t_data *data)
{
	if (tmp->next->next && tmp->prev)
	{
		next = tmp->next->next;
		prev = tmp->prev;
		tmp->next->next->prev = prev;
		tmp->prev->next = next;
		free(tmp->next);
		free(tmp);
	}
	else if (!tmp->next->next && tmp->prev)
	{
		tmp->prev->next = next;
		free(tmp->next);
		free(tmp);
	}
	else if (!tmp->prev && tmp->next->next)
	{
		tmp->next->next->prev = NULL;
		data->export = data->export->next->next;
		free(tmp->next);
		free(tmp);
	}
}

void	unset_export(t_data *data, t_lst **lst, int i, int x)
{
	t_lst	*next;
	t_lst	*prev;
	t_lst	*tmp;

	next = NULL;
	prev = NULL;
	tmp = (*lst);
	while (tmp)
	{
		if (i == x)
			unset_normed(tmp, next, prev, data);
		i++;
		tmp = tmp->next;
	}
}

int	ft_unset(t_data *data)
{
	int		i;
	int		x;
	t_lst	*next;
	t_lst	*prev;

	next = NULL;
	prev = NULL;
	i = 0;
	x = check_exicting(data, data->str[1]);
	if (i == -1)
		return (0);
	unset_export(data, &data->export, i, x);
	return (0);
}
