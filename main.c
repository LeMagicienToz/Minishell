/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/09 11:37:32 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char const **argv)
{
	char	*command_buffer;

	while (1)
	{
		command_buffer = readline("test> ");
		if (ft_strlen(command_buffer) > 0)
		{
			printf("%s\n", command_buffer);
		}
	}
	return (0);
}
