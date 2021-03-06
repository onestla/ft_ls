/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:15:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/18 14:22:19 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_infolen(t_info *info)
{
	int mlen;

	mlen = 0;
	while (info)
	{
		if (mlen < (int)ft_strlen(info->name))
			mlen = ft_strlen(info->name);
		info = info->next;
	}
	return (mlen);
}

void	ls_print_1(t_info *info)
{
	while (info)
	{
		ft_printf("%s\n", info->name);
		info = info->next;
	}
}

void	ls_print_l(t_info *info, char *path, int type, char *opt)
{
	t_info	*tmp;
	int		count;
	int		*len;

	count = 0;
	tmp = info;
	(type != 2) ? ft_printf("total %d\n", ls_n_blocks(info)) : 0;
	while (tmp)
	{
		ls_sprint_rest(tmp, path, opt, type);
		tmp = tmp->next;
	}
	if (!(len = ls_infolen_l(info)))
		return ;
	while (info)
	{
		ls_print_filetype(info);
		ls_print_rights(info, path);
		count = -1;
		while (info->ligne[++count + 1])
			ft_printf("%*s", len[count] + 1, info->ligne[count]);
		ft_printf(" %s\n", info->ligne[count]);
		info = info->next;
	}
	free(len);
}

void	ls_router(char *opt, t_info *info, char *path, int type)
{
	if (!info)
		return ;
	if (ft_cisin(opt, 'g') || ft_cisin(opt, 'l'))
		ls_print_l(info, path, type, opt);
	else
		ls_print_1(info);
}
