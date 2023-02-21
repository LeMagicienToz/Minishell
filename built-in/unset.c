/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:08:10 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 16:23:25 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	unset_normed_env(t_lst *tmp, t_lst *next, t_lst *prev, t_data *data)
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
		data->env = data->env->next->next;
		free(tmp->next);
		free(tmp);
	}
}

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

void	unset_export(t_data *data, t_lst **lst, int l, int x)
{
	t_lst	*next;
	t_lst	*prev;
	t_lst	*tmp;
	int		i;

	i = 0;
	next = NULL;
	prev = NULL;
	tmp = (*lst);
	while (tmp)
	{
		if (i == x)
		{
			if (l == 0)
				unset_normed(tmp, next, prev, data);
			else
				unset_normed_env(tmp, next, prev, data);
			tmp = (*lst);
		}
		i++;
		tmp = tmp->next;
	}
	remake_envi(data);
}

int	parcing_unset(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!data->str[1])
		return (0);
	while (data->str[j])
	{
		while (data->str[j][i])
		{
			if (data->str[j][i] == '=')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_unset(t_data *data)
{
	int		i;
	int		x;
	int		k;
	t_lst	*next;
	t_lst	*prev;

	next = NULL;
	prev = NULL;
	i = 1;
	if (parcing_unset(data) == 0)
		return (erreur_status(1, "Erreur: Parcing unset", data, 0), 0);
	while (data->str[i])
	{
		x = check_exicting_exp(data, data->str[i]);
		if (x == -1)
			return (0);
		unset_export(data, &data->export, 0, x);
		k = check_exicting_env(data, data->str[i++]);
		if (k == -1)
			return (0);
		unset_export(data, &data->env, 1, k);
	}
	return (0);
}
