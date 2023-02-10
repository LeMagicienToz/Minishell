/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/02/10 00:47:10 by muteza           ###   ########.fr       */
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

void	print_export_in_pipe(t_data *data, t_lst *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (i % 2 == 0)
		{
			write(data->fd[1], "declare -x ", 11);
			write(data->fd[1], tmp->content, ft_strlen(tmp->content));
		}
		else if (tmp->typeout == 0)
		{
			write(data->fd[1], (char *)DBQUOTE, 1);
			write(data->fd[1], tmp->content, ft_strlen(tmp->content));
			write(data->fd[1], (char *)DBQUOTE, 1);
			write(data->fd[1], "\n", 1);
		}
		else
			write(data->fd[1], "\n", 1);
		i++;
		tmp = tmp->next;
	}
}

void	print_export(t_data *data, t_lst *tmp)
{
	int	i;

	(void)data;
	i = 0;
	while (tmp)
	{
		if (i % 2 == 0)
		{
			if (tmp->typeout == 0)
				printf("declare -x %s", tmp->content);
			else
			{
				write(1, "declare -x ", 11);
				write(1, tmp->content, ft_strlen(tmp->content) - 1);
			}
		}
		else if (tmp->typeout == 0)
			printf("%c%s%c\n", DBQUOTECODE, tmp->content, DBQUOTECODE);
		else
			printf("\n");
		i++;
		tmp = tmp->next;
	}
}

void	ft_export(t_data *data, t_lst *lst)
{
	int		k;
	t_lst	*tmp;

	k = 0;
	(void)lst;
	if (data->str[1])
	{
		k = 1;
		check_equal(data);
	}
	tmp = data->export;
	if (k == 0)
	{
		if (lst->next)
			print_export_in_pipe(data, tmp);
		else
			print_export(data, tmp);
	}
}
