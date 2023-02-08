/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:53:37 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 19:53:22 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_data *data, t_lst *lst)
{
	char	cwd[1025];
	char	*str;

	str = getcwd(cwd, sizeof(cwd));
	if (str == NULL)
		str = data->save_builtin;
	if (lst->next)
	{
		write(data->fd[1], str, ft_strlen(str));
		write(data->fd[1], "\n", 1);
	}
	else
		printf("%s\n", str);
}
