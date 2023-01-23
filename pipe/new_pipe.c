/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/01/23 17:53:26 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	more_pipe(t_data *data, t_lst *lst)
{
	// (void)lst;
	if (pipe(data->fd) == -1)
		perror("pipe blem\n");
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		dup2(data->save, 0); // changer la sortie vers le pipe
		if (lst->next)
			dup2(data->fd[1], 1); // on change l'entree vers le pipe
		if (data->save != 0)
			close(data->save);
		close(data->fd[0]);
		close(data->fd[1]);
		if (check_builtin(data, lst) == 0)
			execve(data->path, data->str, data->envp);
	}
	// if (data->id == 0)
	// 	kill(data->id, SIGKILL);
	if (data->save != 0)
		close(data->save);
	data->save = data->fd[0];
	close(data->fd[1]);
}
