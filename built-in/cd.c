/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:22:26 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 02:26:22 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*go_to_home(t_data *data)
{
	t_lst	*tmp;
	char	*str;

	tmp = data->env;
	while (tmp)
	{
		if (tmp->next && ft_strcmp(tmp->content, "HOME=") == 0)
		{
			tmp = tmp->next;
			str = tmp->content;
			return (str);
		}
		tmp = tmp->next;
	}
	erreur_status(1, "ERROR: Can't find HOME in PATH", data, 0);
	return ("NULL");
}

void	ft_cd_normed(t_data *data, char	*tmp)
{
	if (!tmp)
	{
		free(tmp);
		erreur_status(1, "ERROR: HOME is not set", data, 0);
	}
	else
		chdir(tmp);
	free(tmp);
}

int	ft_cd(t_data *data, t_lst *lst)
{
	char	cwd[1025];
	char	*str;
	char	*tmp;
	int		i;

	(void)lst;
	i = 0;
	if (!getcwd(cwd, sizeof(cwd)))
		return (chdir(data->str[1]));
	str = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (data->maxindex != 0)
		return (free(str), 0);
	if (data->str[1] == 0)
	{
		tmp = ft_strdup(go_to_home(data));
		ft_cd_normed(data, tmp);
		return (0);
	}
	i = chdir(data->str[1]);
	free(data->save_builtin);
	data->save_builtin = getcwd(NULL, sizeof(cwd));
	if (i == -1)
		erreur_status(1, "ERROR: Something goes wrong with cd ARGS", data, 0);
	return (free(str), 0);
}
