/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:07:15 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 16:52:36 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int count;

	count = 0;
	if ((int)n == 0)
		return (0);
	while (s1[count] && s2[count] && count < (int)n - 1)
	{
		if (s1[count] != s2[count])
			break ;
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
