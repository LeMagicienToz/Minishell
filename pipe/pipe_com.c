/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/09 15:56:21 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	pipex_bon(t_data *data)
// {
// 	data->fd;
// }

void	init_pipe(t_lst *lst, t_data *data)
{
	int	i;

	i = 0;
	(void)lst;
	data->fd = malloc((sizeof (int *)) * data->maxindex);
	while (i != data->maxindex)
	{
		data->fd[i] = malloc(2);
		i++;
	}
	i = 0;
	while (i != data->maxindex)
	{
		if (pipe(data->fd[i]) == -1)
			exit (0);
		i++;
	}
}

void	fork_maker(t_lst *lst, t_data *data)
{
	init_pipe(lst, data);
	// init_fork(lst, data);
}

// void	get_path_in_struct(t_data *data)
// {
// 	char	*buff_command;

// 	data->path_uno;
// }

void	pipe_com(t_lst *lst, t_data *data)
{
	fork_maker(lst, data);
	// get_path_in_struct(data);
}
