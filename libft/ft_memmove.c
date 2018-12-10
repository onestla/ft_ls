/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:02:52 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/10 15:49:28 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	count;

	if (dst > src)
	{
		len--;
		while ((int)len >= 0)
		{
			((char*)dst)[len] = ((char*)src)[len];
			len--;
		}
	}
	else
	{
		count = 0;
		while (count < (int)len)
		{
			((char*)dst)[count] = ((char*)src)[count];
			count++;
		}
	}
	return (dst);
}
