/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/02/01 13:24:24 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	sort_node(t_lst **export)
{
	int		i;
	t_lst	*tmp;
	char	*str;

	i = 1;
	tmp = *export;
	while (i && tmp)
	{
		tmp = *export;
		i = 0;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				str = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = str;
				i = 1;
				tmp = *export;
			}
			tmp = tmp->next;
		}
	}
	tmp = *export;
}

int	is_sort(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->envp[i])
		i++;
	while (data->exp[k])
		k++;
	if (k < i)
		return (0);
	else
		return (1);
}

int	put_tab_in_lst(t_data *data)
{
	int		i;
	int		k;
	char	*str;
	t_lst	*node;

	k = 1;
	data->maxindex = 0;
	str = malloc(sizeof(char) * (ft_strlen(data->exp[0]) + 11));
	str = ft_strjoin("declare -x ", data->exp[0]);
	data->export = create_node(data, str);
	node = data->export;
	free(str);
	i = 0;
	while (data->exp[i])
		i++;
	while (k < i)
	{
		data->maxindex++;
		str = malloc(sizeof(char) * (ft_strlen(data->exp[k]) + 11));
		str = ft_strjoin("declare -x ", data->exp[k]);
		node = create_node(data, str);
		addback(node, &data->export);
		free(str);
		k++;
	}
	sort_node(&data->export);
	return (0);
}

void	ft_export(t_data *data, t_lst *lst)
{
	int		k;
	t_lst	*tmp;

	(void)lst;
	k = 0;
	tmp = data->export;
	if (data->str[1])
		k = check_equal(data);
	if (k == 0)
	{
		while (data->export)
		{
			printf("%s\n", data->export->content);
			data->export = data->export->next;
		}
	}
}
