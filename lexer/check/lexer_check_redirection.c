/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:03:53 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/21 16:24:58 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	red_next_i(int i, int x)
{
	if (x == DBROUT || x == DBRIN)
		i = i + 2;
	else
		i = i + 1;
	return (i);
}

int	red_get_y(int x)
{
	int	y;

	if (x == ROUT || x == DBROUT)
		y = INCODE;
	else
		y = OUTCODE;
	return (y);
}

int	red_get_x(int x)
{
	if (x == ROUT || x == DBROUT)
		x = OUTCODE;
	else
		x = INCODE;
	return (x);
}

int	red_check_norm(char *str, int x, int *i)
{
	int	y;
	int	z;

	z = 1;
	x = red_get_x(x);
	y = red_get_y(x);
	while (str[*i] && str[*i] != y && str[*i] != x)
	{
		if (str[*i] == QUOTECODE || str[*i] == DBQUOTECODE)
		{
			(*i)++;
			while (str[*i] && str[*i] != DBQUOTECODE \
			&& str[*i] != QUOTECODE)
			{
				z = 0;
				(*i)++;
			}
			(*i)++;
		}
		if (check_token(str[(*i)++], (char)0) == TEXT)
			z = 0;
	}
	return (z);
}

int	redirection_check(char *str, t_data *data)
{
	int	i;
	int	z;
	int	x;

	z = 0;
	i = 0;
	while (str[i])
	{
		x = check_token(str[i], str[i + 1]);
		if (x == ROUT || x == DBROUT || x == RIN || x == DBRIN)
		{
			i = red_next_i(i, x);
			z = red_check_norm(str, x, &i);
			if (z != 0)
				break ;
		}
		else
			i++;
	}
	if (z != 0)
		erreur_status(258, "Erreur: Redirection impossible", data, 0);
	return (z);
}
