/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uteza <uteza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/30 19:24:06 by uteza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	char	*command_buffer;
	char	**input_minishell;

	using_history();
	while (1)
	{
		command_buffer = readline("Minishello $");
		if (ft_strlen(command_buffer) && ft_check_word(command_buffer))
		{
			command_buffer = ft_stripwhite(command_buffer);
			add_history(command_buffer);
			input_minishell = ft_split(command_buffer, ' ');
			check_command(input_minishell, envp);
			if (get_cmd(command_buffer))
			{	
				free(command_buffer);
				break ;
			}
		}
		free(command_buffer);
	}
	return (0);
}
