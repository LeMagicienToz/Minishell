/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2023/02/14 20:30:38 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_is_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (0);
	else if (ft_strcmp(str, "pwd") == 0)
		return (0);
	else if (ft_strcmp(str, "env") == 0)
		return (0);
	else if (ft_strcmp(str, "export") == 0)
		return (0);
	else if (ft_strcmp(str, "echo") == 0)
		return (0);
	else if (ft_strcmp(str, "unset") == 0)
		return (0);
	else if (ft_strcmp(str, "exit") == 0)
		return (0);
/*--------- DEBUG ----------*/
	else if (ft_strcmp(str, "leaks") == 0)
		return(system("leaks Minishell"), 1);
/*--------------------------*/
	else
		return (1);
}

int	redir_builtin(t_data *data, t_lst *lst)
{
	if (ft_strcmp(data->str[0], "export") == 0 && !data->str[1])
		exp_redir(data, lst);
	else if (ft_strcmp(data->str[0], "pwd") == 0)
		pwd_redir(data, lst);
	else if (ft_strcmp(data->str[0], "env") == 0)
		env_redir(data, lst);
	else if (ft_strcmp(data->str[0], "echo") == 0)
		echo_redir(data, lst);
	return (0);
}

int	builtin_pipe(t_data *data, t_lst *lst)
{
	data->id = fork();
	if (data->id == 0)
	{
		data->path = get_path(data->envp, data->str[0], data);
		data->k = 1;
		dup2(data->save, 0);
		if (lst->next)
			dup2(data->fd[1], 1);
		if (data->save != 0)
			close(data->save);
		close(data->fd[0]);
		close(data->fd[1]);
		builtin_no_pipe(data, lst);
		kill(0, SIGKILL);
	}
	return (1);
}

int	builtin_no_pipe(t_data *data, t_lst *lst)
{
	if (check_redir(data, lst) == 1)
	{
		if (ft_strcmp(data->str[0], "export") == 0)
			ft_export(data, lst);
		else if (ft_strcmp("pwd", data->str[0]) == 0)
			ft_pwd(data, lst);
		else if (ft_strcmp(data->str[0], "cd") == 0)
			ft_cd(data, lst);
		else if (ft_strcmp(data->str[0], "env") == 0)
			ft_env(data, lst);
		else if (ft_strcmp(data->str[0], "echo") == 0)
			ft_echo(data, lst);
		else if (ft_strcmp(data->str[0], "unset") == 0)
			ft_unset(data);
		else if (ft_strcmp(data->str[0], "exit") == 0)
			ft_exit(data);
		return (1);
	}
	else
		redir_builtin(data, lst);
	return (1);
}
