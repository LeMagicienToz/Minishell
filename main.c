/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/14 21:41:02 by rperrin          ###   ########.fr       */
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
	t_data	data;
	t_lst	*lst;
	t_lexer	*lexer;

	lexer = NULL;
	lst = NULL;
	data.export = NULL;
	data.env = NULL;
	if (init_data(&data, envp) == 1)
		return (0);
	init_exp(&data);
	echo_control_seq(0);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
		if (!data.input)
			data.input = readline("8-----> ");
		if (!data.input)
			return (0);
		if (data.input)
		{	
			if (ft_strcmp(data.input, "exit") == 0)
				return (0);
		}
		add_history(data.input);
		data.check = check_lexer_error(data.input, &data);
		if (data.check == 0)
			launch(&data, lst, lexer);
		else
			get_error(&data);
	}
	return (0);
}
