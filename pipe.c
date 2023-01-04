/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:46:19 by muteza            #+#    #+#             */
/*   Updated: 2023/01/04 18:50:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	one_command(t_lst *lst, t_data *data)
{
	(void)data;
	char	**command = NULL;
	t_lst	*tmp;

	tmp = lst;
	if (ft_lstsize(lst) == 1)
	{
		command[0] = lst->content;
		
	}
	else
	{
		command = ft_split(tmp->content, ' ');
		printf("%s\n", tmp->content);
	}
}

char	**check_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;
	char	**command;

	command = NULL;
	tmp = lst;
	i = 0;
	if (data->maxindex == 0)
		one_command(lst, data);
	else
	{
	printf("%s\n", tmp->content);
	while (tmp)
	{
	printf("AAAAAAa\n");
		tmp = tmp->next;
		// ft_strcpy(command[i], tmp->content);
		i++;
		printf("%s\n", command[i]);
	}
	}
	return (NULL);
}
