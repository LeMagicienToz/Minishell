/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/10 19:18:44 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_command_in_tab(t_data *data, t_lst *lst, int i)
{
	int		k;
	t_lst	*tmp;

	//here
	k = 1;
	tmp = lst;
	data->str = malloc(sizeof(char *) * 3);
	data->str[k + 1] = NULL;
	while (tmp && (tmp->index == i))
	{
		if (tmp->next != NULL && tmp->next->index == tmp->index)
		{
			data->str[i] = ft_strdup(tmp->content);
			data->str[k] = ft_strdup(tmp->next->content);
		}
		else if (tmp->next->index == tmp->index)
		{
			// printf("HERERE\n");
			data->str[i] = ft_strdup(tmp->content);
		}
		tmp = tmp->next;
	}
}

void	pipex_mod(t_data *data, int i, t_lst *lst)
{
	pid_t	id;
	// char *const lol = "ls";

	get_command_in_tab(data, lst, i);
	// printf("%s\n", data->envp[1]);
	// printf("%s\n", data->path);
	init_pipe(lst, data);
	id = fork();
	// printf("aaahah\n");
	if (id == 0)
	{
		data->path = get_path(data->envp, data->str[i]);
		printf("path = %s\n", data->path);
		// printf("1 ere ligne env = %s\n", data->envp[0]);
		// printf("command = %s %s\n", data->str[0], data->str[1]);
		// close(data->fd[i][1]);
		// dup2(data->fd[i][0], 0);
		// printf("%s\n %s\n", data->str[0],data->str[1]);
		// close(data->fd[i + 1][0]);
		// dup2(data->fd[i + 1][1], 1);
		execve(data->path, data->str, data->envp);
		exit(0);
	}
	else
		wait(&id);
		// printf("dhwaudhwadjkamw\n");
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
