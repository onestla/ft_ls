/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:15:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/12 08:57:03 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print(t_info *info)
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
	if (ft_cisin(opt, 'l'))
		ls_print_l(info);
	if (ft_cisin(opt, 't'))
		ls_print(sort_by_mtime(info));
	else
		ls_print(info);
}
