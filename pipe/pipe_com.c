/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/12 13:34:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int make_pipe(int i, t_data *data)
{
	if ((i % 2) == 0)
	{
		if (pipe(data->fd[0]) == -1)
			perror("pipe does not work");
		return (0);
	}
	else
	{
		if (pipe(data->fd[1]) == -1)
			perror("pipe does not work");
		return (1);
	}
}

void get_command_in_tab(t_data *data, t_lst *lst, int i)
{
	int	k;

	k = make_pipe(i, data);
	data->id = malloc(sizeof(pid_t) * (data->maxindex ));
	data->id[i] = fork();
	printf("bouuuuh\n");
	if (data->id[i] == 0)
	{
		if (i >= 1 && k == 0)
		{
			printf("bouuuuh1\n");
			close(data->fd[1][0]);
			close(data->fd[1][1]);
			pipex_mod(data, i, lst);
		}
		else if (i >= 1 && k == 1)
		{
			printf("bouuuuh2\n");
			close(data->fd[0][0]);
			close(data->fd[0][1]);
			pipex_mod(data, i, lst);
		}
		else
		{
			printf("bouuuuh3\n");
			data->path = get_path(data->envp, data->str[0]);
			execve(data->path, data->str, data->envp);
		}
	}
	wait(&data->id[i]);
}

void pipex_mod(t_data *data, int i, t_lst *lst)
{
	(void)lst;
	if (data->id[i] == 0)
	{
		data->path = get_path(data->envp, data->str[i]);
		dup2(data->fd[0][0], data->fd[1][0]);
		dup2(data->fd[1][1], data->fd[0][1]);
		execve(data->path, data->str, data->envp);
	}
	exit(0);
	wait(&data->id[i]);
}

void init_fork_pipe(t_lst *lst, t_data *data)
{
	int i;
	t_lst *tmp;

	tmp = lst;
	i = 0;
	put_lst_in_tab(data, i, lst);
	while (data->str[i])
	{
		get_command_in_tab(data, lst, i);
		// data->str[i] = ft_strdup("ls");
		pipex_mod(data, i, lst);
		i++;
	}
}

void put_lst_in_tab(t_data *data, int i, t_lst *lst)
{
	t_lst	*tmp;
	int		k;

	k = 0;
	tmp = lst;
	while (tmp->next && tmp->index != i)
	{
		tmp = tmp->next;
		i++;
	}
	// printf("%s\n", tmp->content);
	data->str = ft_split("ls", ' ');
	// while (data->str[k])
	// {
	// 	printf("%s\n", data->str[k]);
	// 	k++;
	// }
}

// void	init_pipe(t_lst *lst, t_data *data)
// {
//
// }

void pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
	// printf("AAAAa \n");
	wait(NULL);
}
