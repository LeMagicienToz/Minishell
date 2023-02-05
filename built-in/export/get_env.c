/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:00:05 by muteza            #+#    #+#             */
/*   Updated: 2023/02/03 10:43:21 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	int		k;
	t_lst	*tmp;
	char	*res;

	k = 0;
	i = 0;
	res = NULL;
	tmp = data->export;
	while (tmp)
	{
		while ((str[i] && tmp->content[i]) && tmp->content[i] != '=')
		{
			if (tmp->content[i + 11] == str[i])
				k = 1;
			else
				k = 0;
			i++;
		}
		if (k == 1)
		{
			res = ft_substr(tmp->content, i + 12, len_breson(tmp->content, i));
			break ;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (res);
}
