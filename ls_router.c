/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:15:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/11 16:56:53 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_a(t_info *info)
{
	while (info)
	{
		ft_printf("%s\n", info->name);
		info = info->next;
	}
}

void	ls_print_l(t_info *info)
{
	ft_printf("total %d\n", n_blocks(info));
	while (info)
	{
		print_filetype(info);
		print_rights(info);
		print_rest(info);
		info = info->next;
	}
}

void	ls_router(char *opt, t_info *info)
{
	if (*opt == 'a')
		ls_print_a(info);
	if (*opt == 'l')
		ls_print_l(info);
}
