/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2022/12/16 20:17:30 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_builtin(char *command_buffer, char **envp, t_built	*builtin)
{
	(void)envp;
	builtin->str = ft_split(command_buffer, ' ');
	if (ft_strncmp(builtin->str[0], "cd", 2) == 0)
		ft_cd(builtin->str[1], builtin);
	else if (ft_strncmp(builtin->str[0], "pwd", 3) == 0)
		ft_pwd(builtin);
	else
		return (0);
	return (1);
}
