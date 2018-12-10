/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:12:45 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 15:48:28 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[count] || s2[count]) && count < (int)n)
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}
