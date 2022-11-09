/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:08:42 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/21 17:09:51 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < len - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
