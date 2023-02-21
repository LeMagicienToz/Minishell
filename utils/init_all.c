/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:40 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 15:30:51 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init_data(t_data *data, char **envp)
{
	if (!envp)
	{
		data->status = 404;
		get_error(data);
		return (1);
	}
	else
	{
		data->envp = envp;
		data->exp = envp;
	}
	data->maxindex = 0;
	data->status = 0;
	data->input = NULL;
	data->checkexport = 0;
	data->out = 0;
	data->in = 0;
	data->typeout = 0;
	data->n = -1;
	data->stopn = 0;
	data->null = 0;
	data->export = NULL;
	data->env = NULL;
	return (0);
}

void	init_env(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (data->envp[i])
	{
		if (data->envp[i][j++] == EQUALCODE)
		{
			tmp = ft_substr(data->envp[i], 0, j);
			create_token(data, &data->env, tmp);
			free(tmp);
			tmp = ft_substr(data->envp[i], j, (ft_strlen(data->envp[i]) - j));
			create_token(data, &data->env, tmp);
			free(tmp);
			i++;
			j = 0;
		}
	}
}

void	init_exp(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (data->envp[i])
	{
		if (data->envp[i][j++] == EQUALCODE)
		{
			tmp = ft_substr(data->envp[i], 0, j);
			create_token(data, &data->export, tmp);
			free(tmp);
			tmp = ft_substr(data->envp[i], j, (ft_strlen(data->envp[i]) - j));
			create_token(data, &data->export, tmp);
			free(tmp);
			i++;
			j = 0;
		}
	}
	init_env(data);
}
