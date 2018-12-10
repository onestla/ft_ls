/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:09:50 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 14:45:21 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int	count;

	if (n == 0)
		return ;
	count = 0;
	while (count < (int)n)
	{
		((unsigned char*)s)[count] = 0;
		count++;
	}
}
