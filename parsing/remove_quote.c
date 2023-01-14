/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:45:01 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/12 23:29:00 by rperrin          ###   ########.fr       */
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
