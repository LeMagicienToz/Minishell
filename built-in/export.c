/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/01/18 17:11:19 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	triller(char **envp, t_built *builtin, int v)
{
	int	i;

	i = 0;
	printf("%d\n", v);
	while (envp[i])
	{
		ft_strcpy(builtin->tab_exp[i], envp[i]);
		i++;
	}
	// while (builtin->tab_exp[i])
	// 	printf("%s\n", builtin->tab_exp[i]);
	return (0);
}

int	triable(t_built *builtin, char **envp)
{
	int	v;

	v = 0;
	while (envp[v])
		v++;
	triller(envp,builtin,v);
	// builtin->tab_exp = ft_split(envp, '\n');
	// while (triller(envp, builtin) == 1)
	// {
	// 	return (0);
	// }
	return (0);
}

void	ft_export(t_built *builtin, char **envp)
{
	// int	i;

	// i = 0;
	triable(builtin, envp);
}
