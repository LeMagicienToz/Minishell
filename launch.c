/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:31:58 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/16 18:46:00 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	launch(t_data *data, t_lst *lst, t_lexer *lexer)
{
	lexer = create_lexer(lexer, data->input);
	lst = get_parsed(lexer, data);
	data->lexer = lexer;
	if (lst)
	{
		print_lst(lst);
		tiensmax(lst, data);
		free_all(data, &lexer, &lst);
	}
	else if (data->input)
	{
		free_lex(&lexer);
		data->in = 0;
		free(data->input);
		data->input = NULL;
	}
}

void	get_error(t_data *data)
{
	if (data->status == 400)
		printf("Erreur: Les quotes ne sont pas fermées\n");
	if (data->status == 401)
		printf("Erreur: Pipes sans commande\n");
	if (data->status == 402)
		printf("Erreur: || Opérateur OU pas géré\n");
	if (data->status == 403)
		printf("Erreur: Heredoc sans mot de fin\n");
	if (data->status == 404)
		printf("Erreur: Impossible de lancer Minishell sans environnement\n");
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
}
