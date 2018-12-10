/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:18:55 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 17:25:23 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	count1;
	int	count2;

	count1 = ft_strlen(s1);
	count2 = 0;
	while (s2[count2])
	{
		s1[count1] = s2[count2];
		count1++;
		count2++;
	}
	s1[count1] = '\0';
	return (s1);
}
