/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_de_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:07:19 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/10 20:12:31 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pipe_lexer_normed_normed(char *str, int *i, int x)
{
	x = 0;
	while (str[*i] && str[*i] != PIPECODE)
	{
		if (check_token(str[(*i)++], (char)0) == TEXT)
		{
			x = 2;
			break ;
		}
	}
	if (x != 2)
		x = 1;
	return (x);
}

int	check_pipe_lexer_normed(char *str, t_data *data)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == PIPECODE)
			x = check_pipe_lexer_normed_normed(str, &i, x);
		if (x == 1)
			break ;
	}
	if (x == 1)
	{
		data->status = 401;
		return (1);
	}
	return (0);
}

int	check_pipe_lexer(char *str, t_data *data)
{
	static int	x;
	int			i;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == PIPECODE)
			x++;
		else
			x = 0;
		if (x >= 2)
		{
			data->status = 402;
			return (1);
		}
		i++;
	}
	return (check_pipe_lexer_normed(str, data));
}
