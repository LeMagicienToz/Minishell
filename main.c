/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/09 15:08:34 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*command_buffer;

	while (1)
	{
		command_buffer = readline("Minishello 🤌 ");
		if (ft_strlen(command_buffer) > 0)
			printf("%s\n", command_buffer);
	}
	return (0);
}
