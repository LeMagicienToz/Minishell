/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/02/07 17:56:13 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init_fork_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;
	int		stat;

	data->status = 0;
	tmp = lst;
	i = 0;
	data->save = dup(0);
	while (tmp)
	{
		if (pipe(data->fd) == -1)
			perror("pipe blem\n");
		put_lst_in_tab(data, i, tmp);
		if (check_is_builtin(data->str[0]) == 1)
			more_pipe(data, tmp, i);
		else
			builtin_pipe(data, lst);
		if (data->save != 0)
			close(data->save);
		data->save = data->fd[0];
		close(data->fd[1]);
		i++;
		tmp = tmp->next;
	}
	close(data->fd[0]);
	close(data->fd[1]);
	if (data->save != 0)
		close(data->save);
	while (waitpid(0, &stat, 0) > 0)
		;
	// if (!WIFEXITED(stat))
	// {
	// 	data->status = WEXITSTATUS(stat);
	// 	printf("%d\n", data->status);
	// 	return (data->status);
	// }
	return (0);
}

void	put_lst_in_tab(t_data *data, int i, t_lst *tmp)
{
	int		k;

	k = 0;
	if (!tmp)
		exit(0);
	while (tmp && (tmp->index != i))
	{
		tmp = tmp->next;
		i++;
	}
	// printf("command actuel : %s\n", tmp->content);
	data->str = ft_split(tmp->content, ' ');
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
}
