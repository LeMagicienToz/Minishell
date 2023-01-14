/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:27 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/14 17:22:50 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*strdup_token(int len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	return (res);
}

char	*fill_token(char *str)
{
	int		i;
	int		j;
	int		last;
	char	*res;

	j = 0;
	i = 0;
	res = strdup_token(get_len_token(str));
	if (!res)
		return (NULL);
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			i++;
			while (str[i] != last && str[i])
				res[j++] = str[i++];
			if (str[i] == last)
				i++;
		}
		else
			res[j++] = str[i++];
	}
	return (res);
}

t_lst	*detect_token_split(t_data *data, t_lst *lst)
{
	int		j;
	char	*tmp;

	j = 0;
	while (data->lexer[j])
	{
		tmp = fill_token(data->lexer[j]);
		create_token(data, &lst, tmp, j);
		free(tmp);
		j++;
	}
	j = 0;
	while (data->lexer[j])
		free(data->lexer[j++]);
	free(data->lexer);
	return (lst);
}

t_lst	*detect_token(t_data *data, t_lst *lst, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, '|');
	data->lexer = ft_remove_space_lexer(tmp);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	lst = detect_token_split(data, lst);
	return (lst);
}
