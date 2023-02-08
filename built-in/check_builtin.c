/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 21:13:19 by rperrin          ###   ########.fr       */
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

int	builtin_pipe(t_data *data, t_lst *lst)
{
	if (ft_strncmp(data->str[0], "export", 6) == 0)
		ft_export(data, lst);
	else if (ft_strncmp(data->str[0], "pwd", 3) == 0)
		ft_pwd(data, lst);
	else if (ft_strncmp(data->str[0], "env", 3) == 0)
		ft_env(data, lst);
	else if (ft_strncmp(data->str[0], "echo", 4) == 0)
		ft_echo(data, lst);
	else if (ft_strncmp(data->str[0], "unset", 5) == 0)
		ft_unset(data);
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
