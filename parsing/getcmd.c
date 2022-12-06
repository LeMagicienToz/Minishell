/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:35:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/05 15:49:02 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_strlen_without_quote(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != ' ')
	{
		if (str[i] == DBQUOTE)
			i++;
		len++;
		i++;
	}
	return (len);
}

char	*ft_get_cmd(char *input)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * ft_strlen_without_quote(input) + 1);
	i = 0;
	j = 0;
	while (input[i] != ' ')
	{
		while (input[i] == DBQUOTECODE)
			i++;
		res[j] = input[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
