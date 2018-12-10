/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:14:50 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/12 13:49:23 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int count;

	count = 0;
	if (!s)
		return ;
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	ft_putchar('\n');
}
