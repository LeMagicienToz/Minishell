/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:15 by muteza            #+#    #+#             */
/*   Updated: 2023/01/27 13:48:28 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_builtin(t_data *data, t_lst *lst)
{
	(void)lst;
	if (ft_strncmp(data->str[0], "cd", 2) == 0)
		ft_cd(data);
	else if (ft_strncmp(data->str[0], "pwd", 3) == 0)
		ft_pwd(data);
	else if (ft_strncmp(data->str[0], "env", 3) == 0)
		ft_env(data);
	else if (ft_strncmp(data->str[0], "export", 6) == 0)
	{
		printf("aaaa\n");
		ft_export(data);
	}
	else
		return (0);
	return (1);
}
