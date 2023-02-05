/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/05 17:28:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	tiensmax(t_lst *lst, t_data *data)
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
	check_pipe(lst, data);
}

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv,	char **envp)
{
	t_built	builtin;
	t_data	data;
	t_lst	*lst;
	t_lexer	*lexer;

	lexer = NULL;
	lst = NULL;
	init_data(&data, envp);
	put_tab
	sort_node(&data);
	init_exp(&data);
	// put_tab_in_lst(&data);
	builtin.save = "/Users/muteza/Desktop/Minishell";
	while (1)
	{
		data.input = readline("8-----> ");
		add_history(data.input);
		if (check_lexer_error(data.input, &data) != 1)
		{
			lst = get_parsed(create_lexer(lexer, data.input), &data);
			print_lst(lst);
			tiensmax(lst, &data);
			free_all(&data, &lexer, &lst);
		}
		else
		{
			free(data.input);
			data.errorlexer = NULL;
		}
	}
}
