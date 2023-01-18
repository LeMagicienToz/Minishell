/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:53:37 by muteza            #+#    #+#             */
/*   Updated: 2023/01/18 15:21:58 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_data *data)
{
	char	cwd[1025];
	char	*str;

	str = getcwd(cwd, sizeof(cwd));
	if (str == NULL)
		str = data->save_builtin;
	printf("%s\n", str);
}
