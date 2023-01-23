/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/01/23 19:19:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		// printf("%s\n", tmp->content);
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

int	sorting(t_data *data)
{
	int		i;
	int		k;
	char	*str;
	t_lst	*node;

	k = 1;
	str = ft_strjoin("declare -x ", data->envp[0]);
	data->export = create_node(data, str);
	node = data->export;
	i = 0;
	while (data->envp[i])
		i++;
	while (k < i)
	{
		str = ft_strjoin("declare -x ", data->envp[k]);
		node = create_node(data, str);
		addback(node, &data->export);
		k++;
	}
	sort_node(&data->export);
	while (data->export)
	{
		printf("%s\n", data->export->content);
		data->export = data->export->next;
	}
	return (0);
}

int	triable(t_data *data)
{
	int	v;

	v = 0;
	// printf("%d\n", ft_strcmp("coat","daog"));
	sorting(data);
	// while (data->exp[v])
	// {
	// 	printf("%s\n", data->exp[v]);
	// 	v++;
	// }
	return (0);
}

void	ft_export(t_data *data)
{
	triable(data);
}
