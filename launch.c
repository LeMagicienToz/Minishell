/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:31:58 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/21 19:35:00 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	check_lst_launch(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		while (tmp->content[i] == ' ')
			i++;
		if ((int)ft_strlen(tmp->content) == i)
			return (0);
		i = 0;
		tmp = tmp->next;
	}
	return (1);
}

void	launch(t_data *data, t_lst *lst, t_lexer *lexer)
{
	lexer = create_lexer(lexer, data->input);
	lst = get_parsed(lexer, data);
	print_lexer(lexer);
	print_lst(lst);
	data->lexer = lexer;
	if (lst && check_lst_launch(lst))
	{
		tiensmax(lst, data);
		free_all(data, &lexer, &lst);
	}
	else if (data->input)
	{
		data->status = 0;
		if (lst)
			free_lst(&lst);
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
	if (data->status == 404)
		printf("Erreur: Impossible de lancer Minishell sans environnement\n");
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
}
