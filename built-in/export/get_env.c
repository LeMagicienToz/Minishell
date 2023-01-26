/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:00:05 by muteza            #+#    #+#             */
/*   Updated: 2023/01/26 16:37:28 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
			// printf("%c==%c\n", tmp->content[i + 11], str[i]);
			if (tmp->content[i + 11] == str[i])
				k = 1;
			else
				k = 0;
			i++;
		}
		// printf("\n");
		if (k == 1)
		{
			// printf("CACA\n");
			res = ft_substr(tmp->content, i + 12, len_breson(tmp->content, i));
			break ;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (res);
}
