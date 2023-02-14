/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/14 18:51:32 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	handle_sig(int sig)
{
	(void)sig;
	printf("8-----> \n");
}

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
			// printf("nouvelle commande\n");
			last = tmp->index;
		}
		// printf("[%d] - %s\n", tmp->index, tmp->content);
		tmp = tmp->next;
	}
	check_pipe(lst, data);
}

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv,	char **envp)
{
	t_data	data;
	t_lst	*lst;
	t_lexer	*lexer;

	lexer = NULL;
	lst = NULL;
	data.export = NULL;
	data.env = NULL;
	init_data(&data, envp);
	init_exp(&data);
	while (1)
	{
		if (!data.input)
			data.input = readline("8-----> ");
		add_history(data.input);
		data.check = check_lexer_error(data.input, &data);
		if (data.check == 0)
		{
			lst = get_parsed(create_lexer(lexer, data.input), &data);
			print_lst(lst);
			tiensmax(lst, &data);
			free_all(&data, &lexer, &lst);
		}
		else
		{
			// printf("env = %s\n", get_env(&data, "USER"));
			free(data.input);
			data.input = NULL;
			data.errorlexer = NULL;
		}
	}
}
