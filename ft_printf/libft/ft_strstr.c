/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:16:15 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/10 15:50:34 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int count;
	int counta;

	count = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[count])
	{
		counta = 0;
		if (haystack[count] == needle[counta])
		{
			while (haystack[count + counta] == needle[counta] && needle[counta])
				counta++;
			if (needle[counta] == '\0')
				return ((char*)(haystack + count));
		}
		count++;
	}
	return (NULL);
}
