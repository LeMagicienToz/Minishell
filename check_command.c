/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:06 by uteza             #+#    #+#             */
/*   Updated: 2023/01/04 16:15:23 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

char	*parse_path(char *path, char *arg)
{
	char	*exe;
	char	*tmp;
	int		i;

	i = 0;
	while (path[i] && path[i] != ':')
		i++;
	tmp = malloc(sizeof(char) * i + 2);
	if (!tmp)
		exit(0);
	ft_bzero(tmp, i + 2);
	i = 0;
	while (*path && *path != ':')
	{
		tmp[i] = *path;
		path++;
		i++;
	}
	tmp[i] = '/';
	exe = ft_strjoin(tmp, arg);
	free(tmp);
	return (exe);
}

char	*get_path(char **envp, char *arg)
{
	int		i;
	char	*path;
	char	*exe;

	i = 0;
	path = NULL;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!envp[i])
	{
		return (arg);
	}
	path = envp[i] + 5;
	while (*path)
	{
		if (path == envp[i] + 5 || *path == ':')
		{
			exe = parse_path(path + !(path == envp[i] + 5), arg);
			if (!access(exe, F_OK))
				return (exe);
			free(exe);
		}
		path++;
	}
	return (arg);
}

int	count_pipe(char **str)
{
	int	j;
	int	i;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (str[j++])
	{
		while (str[j][i++])
			if (str[j][i] == '|')
				count++;
	}
	return (count);
}

void	fork_init(char **str, char **envp)
{
	pid_t		child_pid;
	int			fd[2];
	char		*path;
	int			i;

	i = 0;
	if (pipe(fd) == -1)
	{
		printf("pipe failed\n");
		return ;
	}
	child_pid  = fork();
	if (child_pid == -1)
	printf("Fork error\n");
	else if (child_pid == 0)
	{
		//child
		path = get_path(envp, str[0]);
		printf("2 path = %s\n", path);
		// close(fd[1]);
		// dup2(fd[0], 0);
		execve(path, str, envp);
		//close(fd[0]);
		exit(0);
		//cmd_fork(path, str, envp);
	}
	else
	{
		//parent
		// path = get_path(envp, str[0]);
		// printf("1 path = %s\n", path);
		// close(fd[0]);
		// dup2(fd[1], 1);
		// execve(path, str, envp);
		// close(fd[1]);
		wait(&child_pid);
	}
}

void wait_fork(pid_t child_pid)
{
	pid_t	tpid;
	int		status;

	tpid = 0;
	while(tpid != child_pid)
		tpid = wait(&status);
}