/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_de_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:07:19 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 16:37:15 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pipe_lexer_normed_normed(char *str, int i, int x)
{
	if (str[i] == PIPECODE)
		return (1);
	while (str[i])
	{
		if (check_token(str[i], (char)0) == TEXT)
			x = 0;
		if (str[i] == PIPECODE && x == 1)
			break ;
		if (str[i++] == PIPECODE)
			x = 1;
	}
	return (x);
}

int	check_pipe_lexer_jpp(char *str, int i, int x)
{
	x = 1;
	while (str[i] && str[i] != PIPECODE)
	{
		if (check_token(str[i--], (char)0) == TEXT)
		{
			x = 0;
			break ;
		}
	}
	return (x);
}

int	check_pipe_lexer_normed(char *str, t_data *data, int g)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (g == 0)
		return (0);
	if (check_pipe_lexer_normed_normed(str, i, x) \
	|| check_pipe_lexer_jpp(str, ft_strlen(str) - 1, x))
	{
		erreur_status(258, "Erreur: Pipes sans commande", data, 0);
		return (1);
	}
	return (0);
}

int	check_pipe_lexer(char *str, t_data *data)
{
	static int	x;
	int			i;
	int			g;

	g = 0;
	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == PIPECODE)
		{
			g = 1;
			x++;
		}
		else
			x = 0;
		if (x >= 2)
		{
			erreur_status(258, "Erreur: || Opérateur OU pas géré", data, 0);
			return (1);
		}
	}
	return (check_pipe_lexer_normed(str, data, g));
}
