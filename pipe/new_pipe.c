/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/07 21:22:35 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	redir(t_data *data, t_lst *lst)
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

int	check_redir(t_data *data, t_lst *lst)
{
	(void)data;
	if (lst->fdin == 0 && lst->fdout == 0)
		return (1);
	return (0);
}

void	more_pipe(t_data *data, t_lst *lst, int i)
{
	(void)i;
	data->id = fork();
	// printf("fesfes\n");
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
	else if (data->id == 0)
		redir(data, lst);
}
