/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/10 00:31:08 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	redir_out(t_data *data, t_lst *lst)
{
	if (check_is_builtin(data->str[0]) == 1)
		data->path = get_path(data->envp, data->str[0]);
	data->k = 1;
	dup2(data->save, 0);
	if (lst->fdout)
		dup2(lst->fdout, 1);
	else
		dup2(lst->fdin, 0);
	if (data->save != 0)
		close(data->save);
	close(data->fd[0]);
	close(data->fd[1]);
	execve(data->path, data->str, data->envp);
}

void	redir_in(t_data *data, t_lst *lst)
{
	if (check_is_builtin(data->str[0]) == 1)
		data->path = get_path(data->envp, data->str[0]);
	data->k = 1;
	dup2(lst->fdin, 0);
	if (lst->fdout)
		dup2(lst->fdout, 1);
	else
		dup2(lst->fdin, 0);
	if (data->save != 0)
		close(data->save);
	close(data->fd[0]);
	close(data->fd[1]);
	execve(data->path, data->str, data->envp);
}

int	check_redir(t_data *data, t_lst *lst)
{
	if (lst->fdin != 0)
		data->k = 1;
	if (lst->fdout != 0)
		data->k = 2;
	if (lst->fdin == 0 && lst->fdout == 0)
		return (1);
	return (0);
}

void	more_pipe(t_data *data, t_lst *lst, int i)
{
	i = 0;
	data->id = fork();
	if (data->id == 0 && check_redir(data, lst) == 1)
	{
		data->path = get_path(data->envp, data->str[0]);
		data->k = 1;
		dup2(data->save, 0);
		if (lst->next)
			dup2(data->fd[1], 1);
		if (data->save != 0)
			close(data->save);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->path, data->str, data->envp);
	}
	else if (data->id == 0 && data->k == 2)
		redir_out(data, lst);
	else if (data->id == 0 && data->k == 1)
		redir_in(data, lst);
}
