/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:23:46 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 17:02:37 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
	size_t n)
{
	int count;

	count = 0;
	while (count < (int)n && ((unsigned char*)src)[count] != (unsigned char)c)
	{
		((char*)dst)[count] = ((char*)src)[count];
		count++;
	}
	if (count == (int)n)
		return (NULL);
	((char*)dst)[count] = ((char*)src)[count];
	return (dst + count + 1);
}
