/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:42:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 16:05:21 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*fill_in(char *str, int i)
{
	int		j;
	int		len;
	char	*res;

	len = 0;
	if (str[i] == OUT)
		i--;
	while (ft_is_space(str[i]) && ft_is_space(str[i + 1]))
		i--;
	j = i;
	while (ft_isprint(str[i--]))
		len++;
	i = j;
	j = 0;
	res = malloc(sizeof(char) * (len + 1));
	while (str[i])
		res[j++] = str[i--];
	return (res);
}

char	*fill_out(char *str, int i)
{
	int		j;
	int		len;
	char	*res;

	len = 0;
	j = i;
	if (str[i] == OUT)
		(i)++;
	while (ft_is_space(str[i]) && ft_is_space(str[i + 1]))
		(i)++;
	while (ft_isprint(str[(i)++]))
		len++;
	i = j;
	j = 0;
	res = malloc(sizeof(char) * (len + 1));
	while (str[i])
		res[j++] = str[(i)++];
	//printf("[%d, %s,] res=%s\n", __LINE__, __FILE__, res);
	return (res);
}
