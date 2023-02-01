/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:27:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/01 13:12:31 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_2str(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		printf("%s\n", str[j]);
		j++;
	}
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			i++;
		else
			break ;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	else
		return (0);
}
