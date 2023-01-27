/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:29:55 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/17 21:18:06 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_len_token(char *str)
{
	int	i;
	int	len;
	int	last;

	i = 0;
	len = 0;
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			i++;
			while (str[i] != last && str[i++])
			{
				if (str[i] == DOLLARCODE)
				{
					while (str[i++] != SPACECODE)
						len++;
				}
			}
				len++;
			if (str[i] == last)
				i++;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	ft_len_space_normed(char *str, int *i, int space)
{
	int	last;

	while (str[*i])
	{
		last = check_separator(str[*i]);
		if (last > 0)
		{
			(*i)++;
			space++;
			while (str[*i] != last)
				(*i)++;
			if (str[(*i)++] == last)
				space++;
		}
		else
		{
			while (str[*i] == SPACECODE && str[*i + 1] == SPACECODE)
			{
				space++;
				(*i)++;
			}
			(*i)++;
		}
	}
	return (space);
}

int	ft_len_space(char *str)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	if (str[i] == SPACECODE)
	{
		while (str[i++] == SPACECODE)
			space++;
	}
	space = ft_len_space_normed(str, &i, space);
	return (i - space);
}
