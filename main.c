/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/27 14:21:46 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include <signal.h>

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
	data.exp = envp;
	put_tab_in_lst(&data);
	printf("%s\n", data.envp[0]);
	builtin.save = "/Users/muteza/Desktop/Minishell";
	data.maxindex = 0;
	while (1)
	{
		printf("AAA\n");
		system("lsof -w -c minishell");
		input = readline("\e[48;2;158;64;155m\e[1m $ ""\e[48;2;0;0;255m M ""\e[48;2;71;169;14m i " \
		"\e[48;2;237;253;0m n ""\e[48;2;253;171;0m i ""\e[48;2;255;0;0m s " "\e[48;2;158;64;155m h ""\e[48;2;0;0;255m e ""\e[48;2;71;169;14m l ""\e[48;2;237;253;0m l "RESET "  ----->" );
		add_history(input);
		// if (!ft_strncmp(input, "debug leaks", ft_strlen(input)))
		// 	system("leaks Minishell");
		// else if (!ft_strncmp(input, "debug leaks all", ft_strlen(input)))
		// 	system("leaks Minishell");
		// printf("%s\n", get_env(&data,"a"));
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
			tiensmax(lst, &data);
			deleteList(&lst);
			data.maxindex = 0;
		// }
		if (input)
			free(input);
	}
	return (0);
}
