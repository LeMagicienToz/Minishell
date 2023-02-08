/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_de_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:07:19 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/02 19:51:29 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pipe_lexer_normed(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == PIPECODE)
		{
			while (str[i] && str[i] != PIPECODE)
			{
				if (check_token(str[i++], (char) NULL) == TEXT)
					return (0);
			}
			data->status = 420;
			return (1);
		}
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
			data->status = 420;
			return (1);
		}
		i++;
	}
	return (check_pipe_lexer_normed(str, data));
}
