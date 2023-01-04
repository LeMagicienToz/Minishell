/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:27 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/02 23:43:37 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_separator(char c)
{
	if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	else if (c == HYPHENCODE)
		return (HYPHENCODE);
	else if (c == SPACECODE)
		return (SPACECODE);
	else
		return (-1);
}

t_lst	*create_node(char *str, int separator)
{
	t_lst		*node;
	static int	index;

	if (!index)
		index = 0;
	node = malloc(sizeof(t_lst));
	node->content = ft_strdup(str);
	node->separator = separator;
	if (ft_strchr(str, '|'))
		index++;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addback(t_lst *node, t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	create_token(t_lst **lst, char *str, int separator)
{
	t_lst	*node;
	int		i;

	i = 0;
	if ((*lst) == NULL)
		(*lst) = create_node(str, separator);
	else
	{
		node = create_node(str, separator);
		addback(node, lst);
	}
}

int	get_len_token(char *str, int i, int last)
{
	int	len;

	len = 0;
	if (last < 0)
	{
		while (check_separator(str[i]) < 0 && str[i++])
			len++;
		return (len);
	}
	while (check_separator(str[i]) != last && str[i++])
		len++;
	return (len);
}

t_lst	*detect_token(t_lst *lst, char *str)
{
	int		i;
	int		j;
	int		len;
	int		last;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		last = check_separator(str[i]);
		if (last > 0)
		{
			i++;
			len = get_len_token(str, i, last);
			tmp = malloc(sizeof(char) * len + 1);
			while (check_separator(str[i]) != last && str[i])
				tmp[j++] = str[i++];
			if (str[i] == last)
				i++;
		}
		else
		{
			len = get_len_token(str, i, last);
			tmp = malloc(sizeof(char) * len + 1);
			while (check_separator(str[i]) < 0 && str[i])
				tmp[j++] = str[i++];
		}
		tmp[j] = '\0';
		create_token(&lst, tmp, last);
		free(tmp);
		j = 0;
		// if (str[i] == '>')
		// 	create_token(&lst, "|");
	}
	return (lst);
}
