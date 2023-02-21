/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/02/21 16:43:55 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	la_magie_opere(t_data *data, t_lst *tmp, t_lst *lst)
{
	if (pipe(data->fd) == -1)
		perror("pipe blem\n");
	put_lst_in_tab(data, &tmp);
	if (check_is_builtin(data->str[0]) == 1)
		more_pipe(data, tmp);
	else
		builtin_no_pipe(data, lst);
	if (data->save != 0)
		close(data->save);
	data->save = data->fd[0];
	close(data->fd[1]);
}

int	init_fork_pipe(t_lst *lst, t_data *data)
{
	t_lst	*tmp;
	int		stat;
	int		i;

	i = 0;
	tmp = lst;
	data->save = dup(0);
	while (tmp)
	{
		la_magie_opere(data, tmp, lst);
		free_data_str(&data->str);
		tmp = tmp->next;
		lst = lst->next;
	}
	close(data->fd[0]);
	close(data->fd[1]);
	if (data->save != 0)
		close(data->save);
	while (waitpid(0, &stat, 0) > 0)
		;
	if (WIFEXITED(stat))
		data->status = WEXITSTATUS(stat);
	return (0);
}

int	put_lst_in_tab(t_data *data, t_lst **lst)
{
	t_lst	*tmp;
	char	*noleaks;

	tmp = (*lst);
	if (!tmp)
		exit(0);
	data->str = ft_split(tmp->content, ' ');
	if (ft_strcmp("exit", data->str[0]) == 0)
		return (ft_exit(data));
	if (!data->str[1])
	{
		noleaks = ft_strdup(data->str[0]);
		free_data_str(&data->str);
		data->str = malloc(sizeof(char *) * 2);
		data->str[0] = ft_strdup(noleaks);
		data->str[1] = NULL;
		free(noleaks);
	}
	else if (ft_strcmp(data->str[0], "echo") == 0)
	{
		noleaks = ft_strdup(data->str[0]);
		put_lst_in_tab_normed(data, tmp, noleaks);
	}
	return (0);
}

void	free_data_str(char ***lol)
{
	int	i;

	i = 0;
	if (*lol)
	{
		while ((*lol)[i])
		{
			free((*lol)[i]);
			(*lol)[i] = NULL;
			i++;
		}
		free(*lol);
	}
	*lol = NULL;
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
}
