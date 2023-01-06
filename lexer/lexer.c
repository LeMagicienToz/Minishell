/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:27 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 21:38:32 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*fill_token(char *str, int *i, int len, char last)
{
	char	*res;
	int		j;

	j = 0;
	if (len == 0)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (last == SPACECODE)
	{
		while (str[*i] == SPACECODE)
			(*i)++;
	}
	while (j != len)
	{
		res[j] = str[(*i)++];
		j++;
	}
	res[j] = '\0';
	return (res);
}

t_lst	*detect_token_split(t_data *data, t_lst *lst, int *i)
{
	char	last;
	char	*tmp;
	int		j;
	int		len;

	j = 0;
	while (data->lexer[*i][j])
	{
		last = check_separator(data->lexer[*i][j]);
		len = get_len_token(data->lexer[*i], j, last, data);
		if (len > 0)
		{
			tmp = fill_token(data->lexer[*i], &j, len, last);
			create_token(data, &lst, tmp, *i);
			free(tmp);
		}
		else
			break ;
	}
	return (lst);
}

t_lst	*detect_token(t_data *data, t_lst *lst, char *str)
{
	int		i;

	i = 0;
	data->lexer = ft_split_pipe(str, '|', data);
	if (!data->lexer || check_lexer_error(data->errorlexer))
		return (NULL);
	while (data->lexer[i])
	{
		lst = detect_token_split(data, lst, &i);
		i++;
	}
	if (check_lexer_error(data->errorlexer))
		return (NULL);
	return (lst);
}

int	check_lexer_error(char *error)
{
	if (error)
	{
		ft_printf_fd(1, "Erreur: %s\n", error);
		return (1);
	}
	else
		return (0);
}
