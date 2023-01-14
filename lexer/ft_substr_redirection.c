/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:38:33 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/09 22:58:47 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_get_y(char *str, int i)
{
	int	y;

	y = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != OUT && str[i] != IN && str[i])
		{
			while (str[i] != ' ' && str[i] != OUT && str[i] != IN && str[i++])
				y++;
			return (y);
		}
		i++;
	}
	return (0);
}

void	ft_fill_y(t_data *data, char *str, int i)
{
	int	y;

	y = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != OUT && str[i] != IN && str[i])
		{
			while (str[i] != ' ' && str[i] != OUT && str[i] != IN && str[i])
				data->out[y++] = str[i++];
			break ;
		}
		i++;
	}
	data->out[y] = '\0';
}

static char	*ft_fill_res(char *str, int end)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * end + 1);
	while (j != end)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

static char	*get_res_and_redirection(t_data *data, char *str, int x)
{
	char	*res;
	int		g;

	res = ft_fill_res(str, x);
	g = x;
	x = ft_get_y(str, g);
	if (x == 0)
	{
		data->errorlexer = "no redirection\n";
		return (NULL);
	}
	data->out = malloc(sizeof(char) * x + 1);
	ft_fill_y(data, str, g);
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_get_redirection(t_data *data, char *str)
{
	char	*res;
	int		x;

	x = 0;
	while (str[x])
	{
		if (str[x] == OUT)
			res = get_res_and_redirection(data, str, x);
		if (str[x] == IN)
			res = get_res_and_redirection(data, str, x);
		x++;
	}
	if (!res)
		return (ft_strdup(str));
	return (res);
}
