/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/18 15:45:18 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	more_pipe(t_data *data, t_lst *lst)
{
	signal(SIGINT, signal_other);
	signal(SIGQUIT, signal_handler);
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envi, data->str[0], data);
		data->k = 1;
		dup2(data->save, 0);
		if (lst->fdout != 0)
			dup2(lst->fdout, 1);
		else if (lst->next)
			dup2(data->fd[1], 1);
		if (lst->fdin != 0)
			dup2(lst->fdin, 0);
		if (data->save != 0)
			close(data->save);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->path, data->str, data->envp);
	}
}
