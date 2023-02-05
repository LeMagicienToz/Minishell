/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/02/05 17:29:40 by muteza           ###   ########.fr       */
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

void	ft_export(t_data *data, t_lst *lst)
{
	int		i;
	int		k;
	t_lst	*tmp;

	i = 0;
	(void)lst;
	k = 0;
	if (data->str[1])
		k = check_equal(data);
	tmp = data->export;
	if (k == 0)
	{
		while (tmp)
		{
			if (i % 2 == 0)
				printf("declare -x %s", tmp->content);
			else
				printf("%c%s%c\n", DBQUOTECODE, tmp->content, DBQUOTECODE);
			i++;
			tmp = tmp->next;
		}
	}
}
