/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:42:35 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 19:42:37 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*ls_sort_atime(t_info *info, int rev)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ls_simple_cmp(info->stat.st_atime, tmp->stat.st_atime,
						info->name, tmp->name) < 0 && !rev) ||
					(ls_simple_cmp(info->stat.st_atime, tmp->stat.st_atime,
						info->name, tmp->name) > 0 && rev))
				ls_infoswap(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sort_ctime(t_info *info, int rev)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ls_simple_cmp(info->stat.st_ctime, tmp->stat.st_ctime,
						info->name, tmp->name) < 0 && !rev) ||
					(ls_simple_cmp(info->stat.st_ctime, tmp->stat.st_ctime,
						info->name, tmp->name) > 0 && rev))
				ls_infoswap(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sort_mtime(t_info *info, int rev)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ls_simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime,
						info->name, tmp->name) < 0 && !rev) ||
					(ls_simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime,
						info->name, tmp->name) > 0 && rev))
				ls_infoswap(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sort_name(t_info *info, int rev)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ft_strcmp(info->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(info->name, tmp->name) < 0 && rev))
				ls_infoswap(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sort_size(t_info *info, int rev)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ls_simple_cmp(info->stat.st_size, tmp->stat.st_size,
						info->name, tmp->name) < 0 && !rev) ||
					(ls_simple_cmp(info->stat.st_size, tmp->stat.st_size,
						info->name, tmp->name) > 0 && rev))
				ls_infoswap(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}
