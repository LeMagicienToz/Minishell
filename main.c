/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/04 16:50:03 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	tiensmax(t_lst *lst)
{
	t_lst	*tmp;
	int		last;

	last = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == last + 1)
		{
			printf("nouvelle commande\n");
			last = tmp->index;
		}
		printf("[%d] - %s\n", tmp->index, tmp->content);
		tmp = tmp->next;
	}
}

void deleteList(t_lst** head_ref)
{
 
    /* deref head_ref to get the real head */
    t_lst* current = *head_ref;
    t_lst* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv, __attribute__((unused))char **envp)
{
	// char	**str;
	// t_utils	*u;
	t_built	builtin;
	t_data	data;
	t_lst	*lst;

	lst = NULL;
	builtin.save = "/Users/muteza/Desktop/Minishell";
	// u = malloc(sizeof(t_utils));
	// data->u = u;
	// u->i = 0;
	// u->j = 0;
	// u->len = 0;
	// using_history();
	// tmp = lst;
	// while (tmp)
	// {
	// 	printf("[%d] - %s\n", tmp->index, tmp->content);
	// 	tmp = tmp->next;
	// }
	// return (1);
	while (1)
	{
		lst = detect_token(&data, lst, ft_stripwhite(readline("$Minishell -> ")));
		tiensmax(lst);
		deleteList(&lst);
		data.maxindex = 0;
		// data->input = command_buffer;
		// str = ft_split(data->input, ' ');
		// if (str[0][0] == 'l')
		// if ((u->cmd = get_cmd(command_buffer)) < 0)
		// {
		// 	if (u->cmd == -2)
		// 		break ;
		// }
	}
	return (0);
}
