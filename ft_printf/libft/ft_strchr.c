/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:27:34 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 16:23:31 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return ((char*)(s + count));
		count++;
	}
	if (s[count] == c)
		return ((char*)(s + count));
	return (NULL);
}
