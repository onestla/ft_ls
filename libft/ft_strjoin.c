/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:25:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 15:49:41 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		count;

	count = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(char) * (len + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count])
	{
		str[len + count] = s2[count];
		count++;
	}
	str[len + count] = '\0';
	return (str);
}
