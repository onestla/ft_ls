/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:46:24 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/27 17:18:50 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		len;

	count = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[count] = '-';
	}
	while (count != len && str[len - count - 1] != '-')
	{
		str[len - count - 1] = n % 10 + 48;
		n = n / 10;
		count++;
	}
	str[len] = '\0';
	return (str);
}
