/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:32:12 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/09 02:58:18 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_remove_cmd(char *input, int lencmd)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(input) - lencmd));
	i = lencmd + 1;
	j = 0;
	while (input[i])
		tmp[j++] = input[i++];
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_get_arg(t_utils *u, char *input, int lencmd)
{
	char	*res;
	char	*tmp;

	tmp = ft_remove_cmd(input, lencmd);
	res = ft_remove_space(tmp);
	free (tmp);
	u->i = 0;
	u->j = 0;
	tmp = ft_remove_quote(u, res);
	free(res);
	return (tmp);
}
