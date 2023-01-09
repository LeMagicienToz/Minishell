/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/09 19:49:40 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_command_in_tab(t_data *data, t_lst *lst, int i)
{
	int		k;
	t_lst	*tmp;

	k = 0;
	tmp = lst;
	data->str = malloc(sizeof(char *) * 1);
	while (tmp && (tmp->index == i))
	{
		data->str[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	// printf("%s\n", data->str[0]);
}

void	pipex_mod(t_data *data, int i, t_lst *lst)
{
	pid_t	id;

	get_command_in_tab(data, lst, i);
	data->path = get_path(data->envp, data->str[0]);
	printf("%s\n",data->path);
	init_pipe(lst, data);
	id = fork();
	if (id == 0)
	{
		// close(data->fd[i][1]);
		// dup2(data->fd[i][0], 0);
		// close(data->fd[i + 1][0]);
		// dup2(data->fd[i + 1][1], 1);
		execve(data->path, data->str, data->envp);
	}
	wait(NULL);
}

void	init_fork_pipe(t_lst *lst, t_data *data)
{
	int	i;

	i = 0;
	// while (i <= data->maxindex)
	// {
		pipex_mod(data, i, lst);
	// 	i++;
	// }
}

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

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
	// printf("AAAAa \n");
	wait(NULL);
}
