/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:21:07 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 15:22:26 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int count;

	count = 0;
	while (count < (int)n)
	{
		if (((unsigned char*)s)[count] == (unsigned char)c)
			return ((void*)(s + count));
		count++;
	}
	return (NULL);
}
