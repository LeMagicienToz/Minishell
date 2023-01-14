/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/13 19:39:29 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	here_doc(t_data *data)
// {
	
// }

int	check_here_doc(char *str, t_data *data)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == IN && str[i + 1] == IN)
		{
			i += 2;
			printf("(%c)", str[i]);
			x = 1;
			while (str[i] == SPACECODE)
				i++;
			while (str[i] != IN && str[i] != SPACECODE)
				x = 0;
		}
		i++;
	}
	if (x == 1)
		data->errorlexer = ft_strdup("syntax error near unexpected token `<<'");
	return (x);
}
