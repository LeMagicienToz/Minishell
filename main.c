/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/19 14:09:07 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv, char **envp)
{
	char	*command_buffer;
	char	**str;
	t_data	*data;
	t_utils	*u;
	t_built	builtin;

	builtin.save = "/Users/muteza/Desktop/Minishell";
	data = malloc(sizeof(t_data));
	u = malloc(sizeof(t_utils));
	data->u = u;
	u->i = 0;
	u->j = 0;
	u->len = 0;
	str = NULL;
	using_history();
	while (1)
	{
		command_buffer = ft_stripwhite(readline("$Minishell -> "));
		if (ft_strlen(command_buffer) && ft_check_word(command_buffer))
		{
			add_history(command_buffer);
			data->input = command_buffer;
			str = ft_split(data->input, ' ');
			if ((u->cmd = get_cmd(command_buffer)) < 0)
			{
				if (u->cmd == -2)
					break ;
			}
			else if (check_builtin(command_buffer, envp, &builtin) == 0 || check_pipe(command_buffer) == 0)
			{
				fork_init(str, envp);
			}
		}
	}
	return (0);
}
