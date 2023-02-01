/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/01 14:37:02 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*find_here_doc(char *str)
{
	char	*end;
	int		i;
	int		x;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			i = i + 2;
			while (ft_is_space(str[i]))
				i++;
			x = i;
			while (!ft_is_space(str[i]))
			{
				i++;
			}
			i = x;
		}
		i++;
	}
	str = here_doc(str, fill_here_doc_end(str));
}

char	*here_doc(char *str, char *end)
{
	char	*res;
	char	*tmp;

	while (res != end)
	{
		if (res)
			free(res);
		res = readline("> ");
		if (!str)
			str = ft_strdup(res);
		else
		{
			tmp = ft_strdup(res);
			free(res);
			str = ft_strjoin(tmp, res);
			free(tmp);
		}
	}
	return (str);
}
