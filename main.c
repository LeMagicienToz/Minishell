/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/16 11:28:55 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	main(void)
{
	char	*command_buffer;

	using_history();
	while (1)
	{
		command_buffer = readline("Minishello 🤌  ");
		if (ft_strlen(command_buffer) && ft_check_word(command_buffer))
		{
			command_buffer = ft_stripwhite(command_buffer);
			add_history(command_buffer);
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
