/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:30 by muteza            #+#    #+#             */
/*   Updated: 2023/02/05 16:49:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parcing_export(t_data *data)
{
	int	i;

	i = 0;
	if (ft_isdigit(data->str[1][0]))
		return (0);
	while (data->str[1][i] != '=')
	{
		if ((ft_isalpha(data->str[1][i]) || ft_isdigit(data->str[1][i])))
			i++;
		else
			return (0);
	}
	return (1);
}

void	add_to_export(t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	if (!parcing_export(data))
		exit(0);
	str = ft_strjoin("declare -x ", data->str[1]);
	
}

void	add_to_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		i++;
	data->envp[i] = malloc(sizeof(char) * ft_strlen(data->str[1]) + 1);
	data->envp[i] = ft_strcpy(data->envp[i], data->str[1]);
	i++;
	data->envp[i] = NULL;
	i = 0;
}

int	check_equal(t_data *data)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (data->str[1][k])
	{
		if (data->str[1][k] == '=')
		{
			i = 1;
			add_to_env(data);
			add_to_export(data);
		}
		k++;
	}
	return (i);
}
