/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:15:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/15 11:38:17 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print(t_info *info, char *opt)
{
	int			count;
	int			x;
	size_t		mlen;
	size_t		slen;
	t_info		*tmp;

	mlen = 0;
	tmp = info;
	x = (ft_cisin(opt, '1')) ? 0 : 4;
	while (tmp)
	{
		if (mlen < ft_strlen(tmp->name))
			mlen = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	count = 0;
	while (info)
	{
		if (count > x)
		{
			ft_printf("\n");
			count = 0;
		}
		slen = (ft_strlen(info->name) == mlen ) ? mlen : ft_strlen(info->name);
		ft_printf("%-*s", slen, info->name);
		if (info->next && !ft_cisin(opt, '1'))
			ft_putchar(' ');
		count++;
		info = info->next;
	}
	ft_printf("\n");
}

int		*ls_infolen(t_info *info)
{
	t_info	*tmp;
	int		count;
	int		*len;

	count = 0;
	len = (int*)malloc(sizeof(int) * 9);
	tmp = info;
	while (tmp->ligne[count + 1])
	{
		len[count] = 0;
		while (tmp)
		{
			if ((int)ft_strlen(tmp->ligne[count]) > len[count])
				len[count] = ft_strlen(tmp->ligne[count]);
			tmp = tmp->next;
		}
		tmp = info;
		count++;
	}
	len[count] = 0;
	return (len);
}

void	ls_print_l(t_info *info, char *path, int type, char *opt)
{
	t_info	*tmp;
	int		count;
	int		*len;

	count = 0;
	tmp = info;
	if (type != 2)
		ft_printf("total %d\n", ls_n_blocks(info));
	while (tmp)
	{
		ls_sprint_rest(tmp, path, opt);
		tmp = tmp->next;
	}
	len = ls_infolen(info);
	while (info)
	{
		ls_print_filetype(info);
		ls_print_rights(info, path);
		count = 0;
		while (info->ligne[count + 1])
		{
			ft_printf("%*s", len[count] + 1, info->ligne[count]);
			count++;
		}
		ft_printf(" %s", info->ligne[count]);
		ft_printf("\n");
		info = info->next;
	}
}

void	ls_router(char *opt, t_info *info, char *path, int type)
{
	if (!info)
		return ;
	if (ft_cisin(opt, 'g') || ft_cisin(opt, 'l'))
		ls_print_l(info, path, type, opt);
	else
		ls_print(info, opt);
}
