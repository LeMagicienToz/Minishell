/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/01 11:46:42 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	more_pipe(t_data *data, t_lst *lst, int i)
{
	(void)i;
	if (pipe(data->fd) == -1)
		perror("pipe blem\n");
	data->id = fork();
	if (data->id == 0)
	{
		if (check_is_builtin(data->str[0]) == 1)
			data->path = get_path(data->envp, data->str[0]);
		data->k = 1;
		dup2(data->save, 0);
		if (lst->next)
			dup2(data->fd[1], 1);
		if (data->save != 0)
			close(data->save);
		close(data->fd[0]);
		close(data->fd[1]);
		if (builtin_pipe(data, lst) == 0)
			exit(0);//kill(data->id, SIGKILL);
		else
			execve(data->path, data->str, data->envp);
	}
	// printf("%d\n\n", data->k );
	if (data->save != 0)
		close(data->save);
	data->save = data->fd[0];
	close(data->fd[1]);
}
