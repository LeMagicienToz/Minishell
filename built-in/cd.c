/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:22:26 by muteza            #+#    #+#             */
/*   Updated: 2022/12/16 20:17:42 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_cd(char *name, t_built *builtin)
{
	char	cwd[1025];

	if (name == 0)
		name = "/Users/muteza";
	chdir(name);
	builtin->save = getcwd(cwd, sizeof(cwd));
}
