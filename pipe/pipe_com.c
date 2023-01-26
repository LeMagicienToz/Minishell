/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/26 15:46:24 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_fork_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;

	tmp = lst;
	i = 0;
	data->save = 0;
	while (tmp)
	{
		put_lst_in_tab(data, i, tmp);
		if (check_builtin(data, lst) == 1)
		{
			more_pipe(data, tmp);
		}
		i++;
		tmp = tmp->next;
	}
	if (data->save != 0)
		close(data->save);
	close(data->fd[0]);
	close(data->fd[1]);
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void	put_lst_in_tab(t_data *data, int i, t_lst *tmp)
{
	int		k;

	k = 0;
	while (tmp->next && (tmp->index != i))
	{
		tmp = tmp->next;
		i++;
	}
	printf("command actuel : %s\n", tmp->content);
	data->str = ft_split(tmp->content, ' ');
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
}
