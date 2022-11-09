/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uteza <uteza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/09 14:46:50 by uteza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv)
{
	char	*command_buffer;

	printf("coucou raph");
	while (1)
	{
		command_buffer = readline("test> ");
		if (ft_strlen(command_buffer) > 0)
			printf("%s\n", command_buffer);
	}
	return (0);
}
