/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:15:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/10 22:24:06 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_simple(t_info *info)
{
	while (info)
	{
		ft_printf("%s\n", info->name);
		info = info->next;
	}
}

void	ls_router(char *opt, t_info *info)
{
	if (opt[0] == 'b')
		ft_printf("nike ta reum guigui !!! (ON EST LA...)\n");
	ls_print_simple(info);
}
