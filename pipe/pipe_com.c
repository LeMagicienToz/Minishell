/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/13 15:25:50 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	make_pipe(int i, t_data *data)
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

void	get_command_in_tab(t_data *data, t_lst *lst, int i)
{
	int	k;

	k = make_pipe(i, data);
	if (i >= 1 && k == 1)
	{
		close(data->fd[0][1]);
		close(data->fd[0][0]);
	}
	data->id[i] = fork();
	if (data->id[i] == 0)
	{
		if (i >= 1 && k == 0)
		{
			close(data->fd[1][0]);
			// close(data->fd[1][1]);
			pipex_mod(data, i, lst, k);
		}
		else if (i >= 1 && k == 1)
		{
			// close(data->fd[0][0]);
			// close(data->fd[0][1]);
			// printf("%s\n", data->str[0]);
			pipex_mod(data, i, lst, k);
		}
		else if (i == 0)
		{
			data->path = get_path(data->envp, data->str[0]);
			dup2(data->fd[0][1], 1);
			execve(data->path, data->str, data->envp);
		}
		// printf("AAA\n");
		wait(&data->id[i]);
	}
		// free(data->path);
		// printf("lol");
		// exit(0);
}

void	pipex_mod(t_data *data, int i, t_lst *lst, int k)
{
	(void)lst;
	if (data->id[i] == 0 && k == 1)
	{
		// printf("Here\n");
		data->path = get_path(data->envp, data->str[0]);
		close(data->fd[0][0]);
		dup2(data->fd[0][1], 1);
		execve(data->path, data->str, data->envp);
	}
	else if (data->id[i] == 1 && k == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		dup2(data->fd[0][1], 0);
		dup2(data->fd[0][0], data->fd[1][0]);
		execve(data->path, data->str, data->envp);
	}
	wait(&data->id[i]);
}

void	init_fork_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;

	tmp = lst;
	i = 0;
	// put_lst_in_tab(data, i, tmp);
	data->id = malloc(sizeof(pid_t) * (data->maxindex + 1));
	// printf("AAA\n");
	while (tmp)
	{
		if (!tmp->next)
		{
			put_lst_in_tab(data, i, tmp);
			last_pipe_command(data, tmp, i);
			break ;
		}
		else
		{
			put_lst_in_tab(data, i, tmp);
			get_command_in_tab(data, tmp, i);
			wait(data->id);
			i++;
			tmp = tmp->next;
		}
	}
	exit (0);
}

void	put_lst_in_tab(t_data *data, int i, t_lst *tmp)
{
	int		k;

	k = 0;
	while (tmp->next && tmp->index != i)
	{
		tmp = tmp->next;
		i++;
	}
	printf("command actuel : %s\n", tmp->content);
	data->str = ft_split(tmp->content, ' ');
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
}
