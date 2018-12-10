/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:08:06 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/12 13:49:09 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return ;
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
}
