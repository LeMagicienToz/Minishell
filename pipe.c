/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:46:19 by muteza            #+#    #+#             */
/*   Updated: 2023/01/04 20:12:42 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	one_command(t_lst *lst, t_data *data)
{
	char	**command;
	t_lst	*tmp;
	int		i;
	int		k;

	tmp = lst;
	k = 0;
	i = ft_lstsize(lst);
	command = malloc((sizeof(char**)) * (i + 1));
	if (data->maxindex == 0)
	{
		if (i == 1)
		{
			command[0] = ft_strdup(tmp->content);
			command[1] = NULL;
		}
		else
		{
			while (tmp)
			{
				command[k++] =  ft_strdup(tmp->content);
				tmp = tmp->next;
			}
				command[k] = NULL;
		}
	}
	fork_init(command, data->envp);
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
