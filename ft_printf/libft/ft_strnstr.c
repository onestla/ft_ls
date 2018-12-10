/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:51:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 16:39:42 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int counta;

	count = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[count] && count < (int)len)
	{
		counta = 0;
		if (haystack[count] == needle[counta])
		{
			while (haystack[count + counta] == needle[counta]
				&& needle[counta] && count + counta < (int)len)
				counta++;
			if (needle[counta] == '\0')
				return ((char*)(haystack + count));
		}
		count++;
	}
	return (NULL);
}
