/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:55:41 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 14:49:30 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int count;

	count = 0;
	while (count < (int)len)
	{
		((unsigned char*)b)[count] = c;
		count++;
	}
	return (b);
}
