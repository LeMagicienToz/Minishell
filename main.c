/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/04 01:05:25 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv, __attribute__((unused))char **envp)
{
	char	*command_buffer;
	t_data	*data;
	// int		i;

	// i = 0;
	data = malloc(sizeof(t_data));
	using_history();
	while (1)
	{
		command_buffer = readline("Minishello $");
		if (ft_strlen(command_buffer) && ft_check_word(command_buffer))
		{
			command_buffer = ft_stripwhite(command_buffer);
			add_history(command_buffer);
			data->input = ft_split(command_buffer, ' ');
			data->cmd = ft_get_cmd(data->input[0]);
			ft_printf_fd(1, "%s\n", data->cmd);
			ft_printf_fd(1, "#1 %s\n", ft_get_arg(data->input[1]));
			
			//check_command(input_minishell, envp);
			// if (get_cmd(command_buffer))
			// {	
			// 	free(command_buffer);
			// 	break ;
			// }
		}
		free(command_buffer);
		free(data->input);
	}
	return (0);
}
