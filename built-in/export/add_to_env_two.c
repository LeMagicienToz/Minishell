/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 03:05:41 by muteza            #+#    #+#             */
/*   Updated: 2023/02/11 10:21:20 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_with_no_egual(t_data *data)
{
	char	*tmp;

	data->typeout = 1;
	tmp = ft_strdup(data->str[1]);
	free(data->str[1]);
	data->str[1] = ft_strjoin(tmp, "=");
	free(tmp);
	create_token(data, &data->export, data->str[1], 0);
	free(data->str[1]);
	create_token(data, &data->export, ft_strdup("\0"), 0);
}

void	normed_add_to_export(int i, t_data *data, char *str)
{
	i = 0;
	printf("%s\n", data->str[1]);
	while (data->str[1][i] != '=')
		i++;
	i++;
	str = ft_substr(data->str[1], 0, i);
	create_token(data, &data->export, str, 0);
	free(str);
	str = ft_substr(data->str[1], i, (ft_strlen(data->str[1]) - i));
	create_token(data, &data->export, str, 0);
	free(str);
}

int	check_ex_env(t_lst *tmp, char *check)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, check) == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	free(check);
	return (-1);
}

int	check_ex_exp(t_lst *tmp, char *check)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, check) == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	free(check);
	return (-1);
}

int	check_equal(t_data *data)
{
	int		k;
	int		i;
	t_lst	*tmp;

	tmp = data->export;
	i = 0;
	k = 0;
	while (data->str[1][i])
	{
		if (data->str[1][i] == '=')
			k = 1;
		i++;
	}
	if (k == 1)
	{
		add_to_export(data);
		add_to_env(data);
	}
	else
		add_to_export(data);
	return (i);
}
