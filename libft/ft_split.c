/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:42:35 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/22 01:31:27 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	normecmort(int *i, char const *s, char c)
{
	int	j;

	while (s[*i] && s[*i] == c)
		(*i)++;
	j = 0;
	while (s[*i + j] && s[*i + j] != c)
		j++;
	return (j);
}

static char	**error(char **res, int n)
{
	while (n--)
		free(res[n]);
	free(res);
	return (NULL);
}

static char	**malloc_res(char const *s, char c)
{
	int		nb_word;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	res = malloc(sizeof(char *) * (nb_word + 1));
	if (!res)
		return (NULL);
	res[nb_word] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = malloc_res(s, c);
	if (!res)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		j = normecmort(&i, s, c);
		if (j > 0)
		{
			res[k++] = ft_substr(s, i, j);
			if (!res[k - 1])
				return (error(res, k - 1));
		}
		i = i + j;
	}
	return (res);
}
