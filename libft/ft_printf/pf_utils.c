/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:29:12 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/09 18:29:29 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_replace(char *s, char c1, char c2, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		if (s[count] == c1)
		{
			s[count] = c2;
			return ;
		}
		count++;
	}
}

int		lenall(t_printf *lst)
{
	int nb;

	nb = 0;
	while (lst)
	{
		nb += lst->len;
		lst = lst->next;
	}
	return (nb);
}
