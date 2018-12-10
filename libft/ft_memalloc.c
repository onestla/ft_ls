/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:58:18 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 17:03:58 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;
	int		count;

	if (!(str = malloc(size)))
		return (NULL);
	count = 0;
	while (count < (int)size)
	{
		((char*)str)[count] = 0;
		count++;
	}
	return (str);
}
