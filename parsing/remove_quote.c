/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:45:01 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/09 03:02:09 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_getlen_remove_quote(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == DBQUOTECODE)
		{
			i++;
			while (str[i] != DBQUOTECODE && str[i++])
				len++;
			i++;
		}
		else if (str[i] == QUOTECODE)
		{
			i++;
			while (str[i] != QUOTECODE && str[i++])
				len++;
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

char	*ft_check_quote(char *res, char *str, int i, int code)
{
	while (str[i])
	{
		if (str[i] == code)
			return (res);
		i++;
	}
	free(res);
	res = malloc(sizeof(char) * 2);
	res = ">\0";
	return (res);
}

char	*ft_remove_quote(t_utils *u, char *str)
{
	char	*res;

	res = malloc(sizeof(char) * ft_getlen_remove_quote(str) + 1);
	while (str[u->i])
	{
		if (str[u->i] == DBQUOTECODE)
		{
			u->i++;
			res = ft_check_quote(res, str, u->i, DBQUOTECODE);
			while (str[u->i] != DBQUOTECODE && str[u->i])
				res[u->j++] = str[u->i++];
			u->i++;
		}
		else if (str[u->i] == QUOTECODE)
		{
			u->i++;
			res = ft_check_quote(res, str, u->i, QUOTECODE);
			while (str[u->i] != QUOTECODE && str[u->i])
				res[u->j++] = str[u->i++];
			u->i++;
		}
		else
			res[u->j++] = str[u->i++];
	}
	return (res);
}

// char	*tmp;

	// tmp = ft_remove_quote_norme(u, res);
	// free(res);
