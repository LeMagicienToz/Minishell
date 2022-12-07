/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/07 00:00:08 by raphaelperr      ###   ########.fr       */
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
		command_buffer = ft_stripwhite(readline("Minishello $"));
		if (ft_strlen(command_buffer) && ft_check_word(command_buffer))
		{
			add_history(command_buffer);
			data->input = command_buffer;
			data->cmd = ft_get_cmd(command_buffer);
			data->args = ft_get_arg(command_buffer, ft_strlen(data->cmd));
			//ft_printf_fd(1, "%s\n", data->cmd);
			ft_printf_fd(1, "%s\n", data->args);
			
			//check_command(input_minishell, envp);
			// if (get_cmd(command_buffer))
			// {	
			// 	free(command_buffer);
			// 	break ;
			// }
		}
	}
	return (0);
}
