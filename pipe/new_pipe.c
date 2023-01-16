/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/01/16 15:35:44 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	no_more_command(t_data *data, t_lst *lst)
{
	(void)lst;
	// if (pipe(data->fd) == -1)
	// 	perror("pipe blem\n");
	dup2(data->fd[1], data->save_out);
	close(data->fd[1]);
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		execve(data->path, data->str, data->envp);
	}
	data->ret = dup2(data->fd[0], data->save_in);
	close(data->fd[0]);
	waitpid(data->id, &data->ret, 0);
}

void	more_pipe(t_data *data, t_lst *lst)
{
	(void)lst;
	if (pipe(data->fd) == -1)
		perror("pipe blem\n");
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		close(data->fd[0]);
		data->ret = dup2(data->fd[1], 1); // on change l'entree vers la pipe
		// if (data->ret == -1)
		// 	perror("LDASD\n");
		close(data->fd[1]);
		// redirection();
		execve(data->path, data->str, data->envp);
	}

	// close(fd[1]);
	// dup2(data->fd[1], 1);
		dup2(data->fd[0], 0);
	close(data->fd[0]);
	close(data->fd[1]);
	// waitpid(data->id, &data->ret, 0);
}


void	first_pipe(t_data *data, t_lst *lst)
{
	(void)lst;
	if (pipe(data->fd) == -1)
		perror("pipe blem\n");
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		close(data->fd[0]);
		data->ret = dup2(data->fd[1], 1); // on change l'entree vers la pipe
		// if (data->ret == -1)
		// 	perror("LDASD\n");
		close(data->fd[1]);
		// redirection();
		execve(data->path, data->str, data->envp);
	}

	// close(fd[1]);
	// dup2(data->fd[1], 1);
		dup2(data->fd[0], 0);
	close(data->fd[0]);
	close(data->fd[1]);
	// waitpid(data->id, &data->ret, 0);
}