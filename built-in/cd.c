/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:22:26 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 19:15:24 by rperrin          ###   ########.fr       */
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

char	*ft_cd_token(char *str, t_data *data)
{
	int		i;
	char	*save;
	char	*join;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '~')
		{
			res = ft_substr(str, 0, i - 1);
			join = ft_substr(str, i, ft_strlen(str));
			save = ft_strjoin(res, go_to_home(data));
			free(res);
			res = ft_strjoin(save, join);
			free(save);
			free(join);
		}
	}
	if (!res)
		res = ft_strdup(str);
	return (res);
}

int	check_nb_str(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i] != NULL)
		i++;
	return (i);
}

int	ft_cd(t_data *data, t_lst *lst)
{
	char	cwd[1025];
	char	*str;
	char	*tmp;
	int		i;
	char	*leaks;

	(void)lst;
	i = 0;
	if (check_nb_str(data) == 3)
		return (erreur_status(1, "ERROR: Too many arguments", data, 0), 0);
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
	else
	{
		leaks = ft_strdup(data->str[1]);
		free(data->str[1]);
		data->str[1] = ft_cd_token(leaks, data);
		free(leaks);
	}
	i = chdir(data->str[1]);
	free(data->save_builtin);
	data->save_builtin = getcwd(NULL, sizeof(cwd));
	if (i == -1)
		erreur_status(1, "ERROR: Something goes wrong with cd ARGS", data, 0);
	return (free(str), 0);
}
