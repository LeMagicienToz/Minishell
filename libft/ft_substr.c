/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:54:52 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/25 12:37:22 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	length;

	i = 0;
	if (start > ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	length = ft_strlen(s) - start;
	if (len < length)
		length = len;
	ret = malloc(length + 1);
	if (!ret)
		return (0);
	while (s[i + start] && i < len)
	{
		ret[i] = (char)s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
