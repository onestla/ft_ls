/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:16:45 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/12 12:15:19 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin(char const *s)
{
	int		count;

	count = 0;
	while (s[count] == ' ' || s[count] == '\n' || s[count] == '\t')
		count++;
	return (count);
}

static int	end(char const *s)
{
	int		count;

	count = ft_strlen(s) - 1;
	while (s[count] == ' ' || s[count] == '\n' || s[count] == '\t')
		count--;
	if (count < 0)
		return (ft_strlen(s) - 1);
	return (count);
}

char		*ft_strtrim(char const *s)
{
	int		count;
	int		start;
	int		n;
	char	*str;

	if (!s)
		return (NULL);
	start = begin(s);
	n = end(s);
	if (s[0] == '\0')
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(char) * (n - start + 2))))
		return (NULL);
	count = 0;
	while (start <= n)
	{
		str[count] = s[start];
		start++;
		count++;
	}
	str[count] = '\0';
	return (str);
}
