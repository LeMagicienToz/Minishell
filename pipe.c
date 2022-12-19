/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:46:19 by muteza            #+#    #+#             */
/*   Updated: 2022/12/19 14:06:01 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	check_pipe(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = ft_strlen(str);
	while (i != 0)
	{
		if (str[i] == '|')
			k++;
	}
	if (k == 0)
		return (0);
	else
		return (1);
	// 	split_the_pipe(str);
}
