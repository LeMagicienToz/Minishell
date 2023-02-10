/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 04:09:55 by muteza            #+#    #+#             */
/*   Updated: 2023/02/09 04:31:27 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exp_redir(t_data *data, t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	tmp = data->export;
	i = 0;
	while (tmp)
	{
		if (i % 2 == 0)
		{
			write(lst->fdout, "declare -x ", 11);
			write(lst->fdout, tmp->content, ft_strlen(tmp->content));
		}
		else if (tmp->typeout == 0)
		{
			write(lst->fdout, (char *)DBQUOTE, 1);
			write(lst->fdout, tmp->content, ft_strlen(tmp->content));
			write(lst->fdout, (char *)DBQUOTE, 1);
			write(lst->fdout, "\n", 1);
		}
		else
			write(data->fd[1], "\n", 1);
		i++;
		tmp = tmp->next;
	}
}

void	pwd_redir(t_data *data, t_lst *lst)
{
	char	cwd[1025];
	char	*str;

	str = getcwd(cwd, sizeof(cwd));
	if (str == NULL)
		str = data->save_builtin;
	write(lst->fdout, str, ft_strlen(str));
	write(lst->fdout, "\n", 1);
}

void	env_redir(t_data *data, t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->env;
	while (tmp)
	{
		if (i % 2 == 0)
			write(lst->fdout, tmp->content, ft_strlen(tmp->content));
		else if (tmp->typeout == 0)
		{
			write(lst->fdout, tmp->content, ft_strlen(tmp->content));
			write(lst->fdout, "\n", 1);
		}
		else
			write(lst->fdout, "\n", 1);
		i++;
		tmp = tmp->next;
	}
}

void	echo_redir(t_data *data, t_lst *lst)
{
	if (data->str[1])
	{
		if (lst->n == 1)
			write(lst->fdout, data->str[1], ft_strlen(data->str[1]));
		else
		{
			write(lst->fdout, data->str[1], ft_strlen(data->str[1]));
			write(lst->fdout, "\n", 1);
		}
	}
	else if (lst->n != 1)
		write(lst->fdout, "\n", 1);
}
