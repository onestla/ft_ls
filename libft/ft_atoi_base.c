/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:21:49 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/12 15:11:14 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(char *str, int base)
{
	int	res;
	int	signe;

	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	signe = (*str == '-') ? -1 : 1;
	(*str == '+' || *str == '-') ? str++ : 0;
	while (ft_ncisin("0123456789ABCDEF", *str, base))
		res = res * base + get_value(*str++);
	return (res * signe);
}
