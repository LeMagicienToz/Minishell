/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2022/12/16 18:53:25 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_builtin(char *command_buffer, char **envp)
{
	char	**str;

	str = ft_split(command_buffer, ' ');
	if (ft_strncmp(str[0], "cd", 2) == 0)
		ft_cd(str[1]);
	else if (ft_strncmp(str[0], "pwd", 3) == 0)
		ft_pwd(envp);
	else
		return (0);
	return (1);
}
