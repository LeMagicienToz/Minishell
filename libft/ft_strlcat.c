/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:07:44 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/27 19:43:15 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, unsigned int n)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	t1;
	unsigned int	t2;

	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	i = 0;
	j = 0;
	if (!n || t1 > n)
		return (t2 + n);
	while (dst[i])
		i++;
	while (src[j] && ((i + j) < n - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (t2 + i);
}
