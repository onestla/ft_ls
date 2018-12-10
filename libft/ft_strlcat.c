/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:47:31 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 13:34:25 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	int countd;
	int counts;
	int	d;

	d = ft_strlen(dst);
	countd = ft_strlen(dst);
	counts = 0;
	if ((int)size < countd)
		return (ft_strlen(src) + size);
	while (src[counts] != '\0' && countd < (int)size - 1)
	{
		dst[countd] = src[counts];
		countd++;
		counts++;
	}
	dst[countd] = '\0';
	return (d + ft_strlen(src));
}
