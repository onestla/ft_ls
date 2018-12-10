/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:41:23 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 14:12:08 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int count;

	count = 0;
	if (n == 0)
		return (0);
	while (count < (int)n - 1)
	{
		if (((unsigned char*)s1)[count] != ((unsigned char*)s2)[count])
			break ;
		count++;
	}
	return (((unsigned char*)s1)[count] - ((unsigned char*)s2)[count]);
}
