/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:32:12 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/04 19:59:57 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_strlen_split(char *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = -1;
	while (str[i])
	{
		printf("{%c}\n", str[i]);
		if (str[i] == c && len == -1)
		{
			len++;
			i++;
			while (str[i] != c)
			{
				printf("(%c)\n", str[i]);
				i++;
				len++;
			}
		}
		i++;
	}
	return (len);
}

char	*ft_split_arg(char *str, char c)
{
	char	*res;
	int		i;
	int		j;

	j = -1;
	i = 0;
	res = malloc(sizeof(char) * ft_strlen_split(str, DBQUOTECODE) + 1);
	while (str[i])
	{
		if (str[i] == c && j == -1)
		{
			j++;
			i++;
			while (str[i] != c)
			{
				res[j] = str[i];
				j++;
				i++;
			}
			break ;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_get_arg(char *str)
{
	int		i;
	int		j;
	int		x;
	char	**res;

	res = ft_split(str, DBQUOTECODE);
	len = 0;
	i = 0;
	k = 0;
	while (str[i++][j])
	{
		while (str[i][j++])
		{
			if (str[i][j] == '$' && ft_isdigit(str[i][j + 1])
				str[i]
			if (str[i][j])
		}
	}
	return (res);
}
