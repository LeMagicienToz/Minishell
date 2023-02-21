/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi_repalce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:36:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 01:31:03 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	make_first_envi(t_data *data)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	if (!data->env)
		return (0);
	tmp = data->env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	i = i / 2;
	tmp = data->env;
	data->envi = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp->next->next)
	{
		data->envi[i] = ft_strjoin(tmp->content, tmp->next->content);
		i++;
		tmp = tmp->next->next;
	}
	data->envi[i] = ft_strjoin(tmp->content, tmp->next->content);
	data->envi[i + 1] = NULL;
	return (0);
}

void	remake_envi(t_data *data)
{
	int	i;

	i = 0;
	make_first_envi(data);
	i = 0;
}
