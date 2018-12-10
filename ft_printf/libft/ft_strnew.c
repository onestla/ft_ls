/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:09:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 14:04:34 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		count;

	count = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (count <= (int)size)
	{
		str[count] = '\0';
		count++;
	}
	return (str);
}
