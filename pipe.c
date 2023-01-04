/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:46:19 by muteza            #+#    #+#             */
/*   Updated: 2023/01/04 17:34:05 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

// void	one_command(t_lst *lst)
// {
	
// }

char	**check_pipe(t_lst *lst, t_data *data)
{
	int		i;
	(void)data;
	// int		index;
	t_lst	*tmp;
	char	**command = NULL;

	i = 0;
	tmp = lst;
	// if (index_max == 0)
	// 	one_command(lst);
	printf("%s\n", tmp->content);
	while (tmp)
	{
	printf("AAAAAAa\n");
		tmp = tmp->next;
		// ft_strcpy(command[i], tmp->content);
		i++;
		printf("%s\n", command[i]);
	}
	return (NULL);
}
