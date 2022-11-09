/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:32:12 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/21 21:50:42 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*res;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((sizeof(char) * len) + 1);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		res[i] = s1[i];
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}
