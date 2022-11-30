/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uteza <uteza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:06 by uteza             #+#    #+#             */
/*   Updated: 2022/11/30 19:25:41 by uteza            ###   ########.fr       */
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
        printf("AHAHA");
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

void check_command(char **str, char **envp)
{
    char *path;

    path = get_path(envp, str[0]);
    if (execve(path ,str , envp))
    {
        perror("Not Work\n");
    }
    // printf("%s\n", str);
}
