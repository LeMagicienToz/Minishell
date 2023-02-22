/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:06 by uteza             #+#    #+#             */
/*   Updated: 2023/02/22 01:59:15 by rperrin          ###   ########.fr       */
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

char	*get_path(char **envp, char *arg, t_data *data)
{
	int		i;
	char	*path;
	char	*exe;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!access(data->str[0], X_OK))
		return (data->str[0]);
	else if (!envp[i])
		return (erreur_status(127, "Erreur: pas de PATH", data, 1), NULL);
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
	erreur_status(127, "Erreur: Commande introuvable <3", data, 1);
	return (NULL);
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

void	erreur_status(int status, char *error, t_data *data, int ex)
{
	printf("%s\n", error);
	data->status = status;
	if (ex != 0)
		exit(data->status);
}

void	wait_fork(pid_t child_pid)
{
	pid_t	tpid;
	int		status;

	tpid = 0;
	while (tpid != child_pid)
		tpid = wait(&status);
}
