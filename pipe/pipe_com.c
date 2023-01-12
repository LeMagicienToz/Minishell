/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/12 17:44:43 by muteza           ###   ########.fr       */
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
	data->id[i] = fork();
	printf("bouuuuh\n");
	if (data->id[i] == 0)
	{
		if (i >= 1 && k == 0)
		{
			printf("bouuuuh1\n");
			close(data->fd[1][0]);
			// close(data->fd[1][1]);
			pipex_mod(data, i, lst);
		}
		else if (i >= 1 && k == 1)
		{
			printf("bouuuuh2\n");
			// close(data->fd[0][0]);
			close(data->fd[0][1]);
			// printf("%s\n", data->str[0]);
			pipex_mod(data, i, lst);
		}
		else if (i == 0)
		{
			data->path = get_path(data->envp, data->str[0]);
			dup2(data->fd[0][0], 0);
			dup2(data->fd[0][1], 1);
			execve(data->path, data->str, data->envp);
		}
	}
		// free(data->path);
		// printf("lol");
		// exit(0);
}

void pipex_mod(t_data *data, int i, t_lst *lst)
{
	(void)lst;
	if (data->id[i] == 0)
	{
		data->path = get_path(data->envp, data->str[0]);
		dup2(data->fd[0][0], data->fd[1][0]);
		dup2(data->fd[1][1], data->fd[0][1]);
		execve(data->path, data->str, data->envp);
	}
	// exit (0);
	wait(&data->id[i]);
}

void init_fork_pipe(t_lst *lst, t_data *data)
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
		printf("aiodowiajdwa\n");
		put_lst_in_tab(data, i, tmp);
		get_command_in_tab(data, tmp, i);
		// data->str[i] = ft_strdup("ls");
		pipex_mod(data, i, tmp);
		wait(data->id);
		i++;
		tmp = tmp->next;
	}
}

void put_lst_in_tab(t_data *data, int i, t_lst *tmp)
{
	int		k;

	k = 0;
	while (tmp->next && tmp->index != i)
	{
		tmp = tmp->next;
		i++;
	}
	printf("command actuel : %s\n", tmp->content);
	// printf("%s\n", tmp->content);
	data->str = ft_split(tmp->content, ' ');
	// printf("%s\n", data->str[0]);
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
	// wait(NULL);
}
