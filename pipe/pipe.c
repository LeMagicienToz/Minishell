/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:46:19 by muteza            #+#    #+#             */
/*   Updated: 2023/01/11 17:00:56 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	one_command(t_lst *lst, t_data *data)
{
	t_lst	*tmp;
	int		i;
	int		k;

	tmp = lst;
	k = 0;
	i = ft_lstsize(lst);
	data->command = malloc((sizeof(char **)) * (i + 1));
	if (data->maxindex == 0)
	{
		if (i == 1)
		{
			data->command[0] = ft_strdup(tmp->content);
			data->command[1] = NULL;
		}
		else
		{
			while (tmp)
			{
				data->command[k++] = ft_strdup(tmp->content);
				tmp = tmp->next;
			}
				data->command[k] = NULL;
		}
	}
	fork_init(data->command, data->envp);
}

char	**check_pipe(t_lst *lst, t_data *data)
{
	if (data->maxindex == 0)
		one_command(lst, data);
	else
		pipe_com(lst, data);
	return (NULL);
}
