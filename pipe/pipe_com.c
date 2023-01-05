/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/05 17:22:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	fork_maker(t_lst *lst, t_data *data)
{
	(void)lst;
	pipe(data->fd);
	data->id = fork();
}

// void	get_path_in_struct(t_data *data)
// {
// 	char *
// 	data->path_uno;
// }

void	pipe_com(t_lst *lst, t_data *data)
{
	fork_maker(lst, data);
	// get_path_in_struct(data);
	// if (data->id == 0)
	// {
	// 	close(data->fd[0]);
	// 	dup2(data->f1, 0);
	// 	close(data->f1);
	// 	dup2(data->fd[1], 1);
	// 	close(data->fd[1]);
	// 	execve(data->path_first, data->f_com, 0);
	// }
	// else if (data->id != 0)
	// {
	// 	wait(NULL);
	// 	close (data->fd[1]);
	// 	dup2(data->fd[0], 0);
	// 	close (data->fd[0]);
	// 	dup2(data->f2, 1);
	// 	execve(data->path_second, data->s_com, 0);
	// }
	// return (0);
}
