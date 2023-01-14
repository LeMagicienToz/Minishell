/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/14 15:35:33 by rperrin          ###   ########.fr       */
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
		// printf("dhwaudhwadjkamw\n");
	check_pipe(lst, data);
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
__attribute__((unused))char **argv,	char **envp)
{
	t_built	builtin;
	t_data	data;
	t_lst	*lst;
	char	*input;

	lst = NULL;
	data.envp = envp;
	builtin.save = "/Users/muteza/Desktop/Minishell";
	data.maxindex = 0;
	while (1)
	{
		input = readline("$Minishell -> ");
		add_history(input);
		if (!ft_strncmp(input, "debug leaks", ft_strlen(input)))
			system("leaks Minishell");
		// else if (!ft_strncmp(input, "debug leaks all", ft_strlen(input)))
		// 	system("leaks Minishell");
		// if (check_lexer_error(input, &data) == 1)
		// {
		// 	data.errorlexer = NULL;
		// 	printf("ERREUR\n");
		// }
		// else
		// {
			lst = detect_token(&data, lst, input);
			print_lst(lst);
			// system("leaks Minishell | grep leak | tail -1");
			// tiensmax(lst, &data);
			deleteList(&lst);
			data.maxindex = 0;
		// }
		if (input)
			free(input);
	}
	return (0);
}
