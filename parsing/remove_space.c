/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:47:02 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/14 14:12:06 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_len_space_norme(char *str, int *i, int space)
{
	int	last;

	while (str[*i])
	{
		last = check_separator(str[*i]);
		if (last > 0)
		{
			(*i)++;
			while (str[*i] != last)
				(*i)++;
		}
		else
		{
			while (str[*i] == SPACECODE && str[*i + 1] == SPACECODE)
			{
				space++;
				(*i)++;
			}
		}
		(*i)++;
	}
	return (space);
}

int	ft_len_space(char *str)
{
	int	space;
	int	i;
	int	x;

	x = 0;
	space = 0;
	i = 0;
	if (str[i] == SPACECODE && x == 0)
	{
		x = 1;
		while (str[i++] == SPACECODE)
			space++;
	}
	space = ft_len_space_norme(str, &i, space);
	return (i - space);
}

static char	*ft_remove_space_normed(char *str, char *res, int j, int i)
{
	int	last;

	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			i++;
			while (str[i] != last)
				res[j++] = str[i++];
		}
		else
		{
			while (str[i] == SPACECODE && str[i + 1] == SPACECODE)
				i++;
			res[j++] = str[i++];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_remove_space(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		x;

	x = 0;
	j = 0;
	i = 0;
	res = malloc(sizeof(char) * ft_len_space(str) + 1);
	if (str[i] == SPACECODE && x == 0)
	{
		x = 1;
		while (str[i] == SPACECODE)
			i++;
	}
	res = ft_remove_space_normed(str, res, j, i);
	return (res);
}

char	**ft_remove_space_lexer(char **str)
{
	int		i;
	char	**res;
	int		num_word;

	i = 0;
	num_word = 0;
	while (str[i++])
		num_word++;
	res = malloc(sizeof(char *) * (num_word + 1));
	res[num_word] = NULL;
	i = 0;
	while (str[i])
	{
		res[i] = ft_remove_space(str[i]);
		i++;
	}
	return (res);
}
