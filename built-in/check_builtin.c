/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2023/02/10 00:47:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_is_builtin(char *str)
{
	if (ft_strncmp(str, "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(str, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "env", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "export", 6) == 0)
		return (0);
	else if (ft_strncmp(str, "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(str, "unset", 5) == 0)
		return (0);
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
	if (check_redir(data, lst) == 1)
	{
		if (ft_strcmp(data->str[0], "export") == 0)
			ft_export(data, lst);
		else if (ft_strcmp("pwd", data->str[0]) == 0)
			ft_pwd(data, lst);
		else if (ft_strcmp(data->str[0], "env") == 0)
			ft_env(data, lst);
		else if (ft_strcmp(data->str[0], "echo") == 0)
			ft_echo(data, lst);
		else if (ft_strcmp(data->str[0], "unset") == 0)
			ft_unset(data);
		return (1);
	}
	else
		redir_builtin(data, lst);
	return (1);
}

int	check_builtin(t_data *data, t_lst *lst)
{
	(void)lst;
	if (ft_strncmp(data->str[0], "cd", 2) == 0)
		ft_cd(data);
	else if (ft_strncmp(data->str[0], "pwd", 3) == 0)
		ft_pwd(data, lst);
	else if (ft_strncmp(data->str[0], "env", 3) == 0)
		ft_env(data, lst);
	else if (ft_strncmp(data->str[0], "export", 6) == 0)
		ft_export(data, lst);
	else if (ft_strncmp(data->str[0], "unset", 5) == 0)
		ft_unset(data);
	else
		return (0);
	return (1);
}
