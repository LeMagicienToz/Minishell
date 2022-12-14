/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:45:01 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/12 17:50:19 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_init_res_normed(t_utils *u, char *str, int code)
{
	u->i++;
	while (str[u->i] != code && str[u->i++])
		u->len++;
	u->i++;
}

char	*ft_init_res(t_utils *u, char *str)
{
	while (str[u->i])
	{
		if (str[u->i] == DBQUOTECODE || str[u->i++] == QUOTECODE)
			ft_init_res_normed(u, str, str[u->i]);
		else
		{
			u->len++;
			u->i++;
		}
	}
	u->res = malloc(sizeof(char) * u->len + 1);
	return (u->res);
}

int	ft_check_quote(int i, char *str, int code)
{
	while (str[i])
	{
		if (str[i] == code)
			return (0);
		i++;
	}
	return (1);
}

void	ft_remove_quote_normed(t_utils *u, char *str, int code)
{
	u->i++;
	if (ft_check_quote(u->i, str, code) == 1)
	{
		u->i = -1;
		return ;
	}
	while (str[u->i] != code && str[u->i])
	{
		dprintf(2, "[%c]\n", str[u->i]);
		u->res[u->j] = str[u->i];
		u->i++;
		u->j++;
	}
	// if (u->i == ft_strlen(str) - 1)
	u->i++;
}

char	*ft_remove_quote(t_utils *u, char *str)
{
	char	*res;

	res = ft_init_res(u, str);
	while (str[u->i])
	{
		if (str[u->i] == DBQUOTECODE || str[u->i] == QUOTECODE)
		{
			dprintf(2, "1(%c)\n", str[u->i]);
			ft_remove_quote_normed(u, str, str[u->i]);
			if (u->i == -1)
			{
				free(u->res);
				u->res = malloc(sizeof(char) * 2);
				u->res = ">\0";
				return (u->res);
			}
		}
		else
		{
			//dprintf(2, "test(%p)\n", &str[u->i]);
			u->res[u->j++] = str[u->i++];
			dprintf(2, "2(%c)\n", u->res[u->j]);
		}
	}
	u->res[u->i] = '\0';
	return (u->res);
}
