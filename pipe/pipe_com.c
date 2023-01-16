/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/16 17:28:20 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_fork_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;
	int		k;

	tmp = lst;
	i = 0;
	data->save_out = dup(1);
	data->save_in = dup(0);
	while (tmp)
	{
		if (!tmp->next)
		{
			k = 1;
			printf("ADSDA\n");
			put_lst_in_tab(data, i, tmp);
			no_more_command(data, tmp);
			break ;
		}
		else
		{
			k = 0;
			put_lst_in_tab(data, i, tmp);
			more_pipe(data, tmp);
			i++;
			tmp = tmp->next;
		}
	}
	close(1);
	close(0);
		// while(1);
	exit (0);
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
	// printf("AAA\n");
}
