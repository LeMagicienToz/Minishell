/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:53:37 by muteza            #+#    #+#             */
/*   Updated: 2022/12/16 20:23:39 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_built *builtin)
{
	char	cwd[1025];
	char	*str;

	str = getcwd(cwd, sizeof(cwd));
	if (str == NULL)
		str = builtin->save;
	printf("%s\n", str);
}
