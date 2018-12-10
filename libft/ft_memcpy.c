/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:07:46 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 16:20:41 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	count;

	count = 0;
	while (count < (int)n)
	{
		((char*)dst)[count] = ((char*)src)[count];
		count++;
	}
	return (dst);
}
