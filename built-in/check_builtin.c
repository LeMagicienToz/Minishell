/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2023/01/10 18:30:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_builtin(char *command_buffer, char **envp, t_built	*builtin)
{
	builtin->str = ft_split(command_buffer, ' ');
	if (ft_strncmp(builtin->str[0], "cd", 2) == 0)
		ft_cd(builtin->str[1], builtin);
	else if (ft_strncmp(builtin->str[0], "pwd", 3) == 0)
		ft_pwd(builtin);
	else if (ft_strncmp(builtin->str[0], "env", 3) == 0)
		ft_env(builtin, envp);
	// else if (ft_strncmp(builtin->str[0], "export", 6) == 0)
	// 	ft_export(builtin, envp);
	else
		return (0);
	return (1);
}
