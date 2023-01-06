/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/06 18:34:52 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	pipex_bon(t_data *data)
// {
// 	data->fd;
// }

void	fork_maker(t_lst *lst, t_data *data)
{
	int	i;
	int	id[data->maxindex];
	int	fd[data->maxindex][2];

	(void)lst;
	i = 0;
	while (i != data->maxindex)
	{
		if (pipe(fd[i]))
			exit(0);
		i++;
	}
	while (i != data->maxindex)
	{
		id[i] = fork();
		if (id[i] == -1)
			exit (0);
	}
	
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
