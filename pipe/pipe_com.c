/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/02/10 00:45:30 by muteza           ###   ########.fr       */
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
		put_lst_in_tab(data, i, &tmp);
		if (check_is_builtin(data->str[0]) == 1)
			more_pipe(data, tmp, i);
		else
			builtin_pipe(data, lst, i);
		if (data->save != 0)
			close(data->save);
		data->save = data->fd[0];
		close(data->fd[1]);
		i++;
		tmp = tmp->next;
		lst = lst->next;
	}
	close(data->fd[0]);
	close(data->fd[1]);
	if (data->save != 0)
		close(data->save);
	while (waitpid(0, &stat, 0) > 0)
		;
	// if (SIGINT)
	// {
	// 	printf("dwadwadwa\n");
	// 	exit(0);
	// }
	// else
	// {
	// 	data->err_val = WEXITSTATUS(stat);
	// }
	return (0);
}

void	put_lst_in_tab(t_data *data, int i, t_lst **lst)
{
	int		k;
	t_lst	*tmp;

	tmp = (*lst);
	k = 1;
	(void)i;
	if (!tmp)
		exit(0);
	data->str = ft_split(tmp->content, ' ');
	while (data->str[k])
		free(data->str[k++]);
	if (data->str[1])
		data->str[1] = ft_substr(tmp->content, ft_strlen(data->str[0]) + 1, ft_strlen(tmp->content));
	else
		data->str[1] = NULL;
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
}
