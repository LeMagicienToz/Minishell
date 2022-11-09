/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:00:36 by rperrin           #+#    #+#             */
/*   Updated: 2021/11/03 13:43:15 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*res;
	int		size[2];
	int		start;

	size[0] = 0;
	size[1] = 0;
	if (!s || !set)
		return (NULL);
	while (s[size[0]] && (count(s[size[0]], set) == 1))
		size[0]++;
	if (size[0] >= (int)ft_strlen(s))
		return (ft_strdup(""));
	start = size[0];
	size[0] = ft_strlen(s) - 1;
	while (s[size[0]] && (count(s[size[0]], set) == 1))
		size[0]--;
	res = malloc(sizeof(char) * (size[0] - start + 2));
	if (!res)
		return (NULL);
	while (start <= size[0])
		res[size[1]++] = s[start++];
	res[size[1]] = '\0';
	return (res);
}
