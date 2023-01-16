/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:05:28 by muteza            #+#    #+#             */
/*   Updated: 2023/01/16 14:45:38 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	last_pipe_command(t_data *data, t_lst *tmp, int i)
// {
// 	int	k;

// 	(void)tmp;
// 	k = make_pipe(i, data);
// 	data->id[i] = fork();
// 	if (data->id[i] == 0 && k == 0)
// 	{
// 		data->path = get_path(data->envp, data->str[0]);
// 		printf("DATA PATHito : %s\n", data->path);
// 		dup2(1, data->fd[1][1]);
// 		close(data->fd[1][1]);
// 		dup2(data->fd[1][0], 0);
// 		close(data->fd[1][0]);
// 		execve(data->path, data->str, data->envp);
// 	}
// 	else if (data->id[i] == 0 && k == 1)
// 	{
// 		data->path = get_path(data->envp, data->str[0]);
// 		printf("DATA PATH : %s\n", data->path);
// 		dup2(1, data->fd[0][1]);
// 		close(data->fd[0][1]);
// 		dup2(data->fd[0][0], 0);
// 		close(data->fd[0][0]);
// 		kill(data->id[i], 0);
// 		execve(data->path, data->str, data->envp);
// 		// wait(&data->id[i]);
// 	}
// }
