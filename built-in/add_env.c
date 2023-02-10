/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:00:05 by muteza            #+#    #+#             */
/*   Updated: 2023/02/09 06:35:46 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	parc_export(t_data *data, char *str)
{
	int	i;
	int	k;

	(void)data;
	k = 0;
	i = 12;
	if (!ft_isalpha(str[11]))
	{
		k = 1;
		return (k);
	}
	while (str[i] != '=' && (ft_isalpha(str[i]) || ft_isdigit(str[i])))
		i++;
	if (str[i] != '=')
	{
		k = 1;
		return (k);
	}
	return (k);
}

int	len_breson(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*get_env(t_data *data, char	*str)
{
	int		i;
	int		x;
	t_lst	*tmp;
	char	*res;

	i = 0;
	res = NULL;
	tmp = data->export;
	x = check_exicting_exp(data, str);
	while (tmp)
	{
		if (i == x)
			res = ft_strdup(tmp->next->content);
		tmp = tmp->next;
		i++;
	}
	return (res);
}

int	check_equal_env(t_data *data)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (data->str[1][i])
	{
		if (data->str[1][i] == '=')
			k = 1;
		i++;
	}
	return (k);
}
