/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:29:55 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/13 22:11:39 by rperrin          ###   ########.fr       */
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
