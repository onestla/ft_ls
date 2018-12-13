/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:31:40 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/13 17:52:54 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		simple_cmp(int a, int b, char *s1, char *s2)
{
	if (a == b)
		return (ft_strcmp(s1, s2) * -1);
	return (a - b);
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
			if ((simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime, info->name, tmp->name) < 0 && !rev) || 
					(simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime, info->name, tmp->name) > 0 && rev))
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
			if ((ft_strcmp(info->name, tmp->name) > 0 && !rev) || (ft_strcmp(info->name, tmp->name) < 0 && rev))  
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
			if ((simple_cmp(info->stat.st_size, tmp->stat.st_size, info->name, tmp->name) < 0 && !rev) || 
					(simple_cmp(info->stat.st_size, tmp->stat.st_size, info->name, tmp->name) > 0 && rev))
				ls_infoswap(info, tmp); 
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sortrouter(t_info *info, char *opt)
{
	if (ft_cisin(opt, 'S'))
		return (ls_sort_size(info, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 't'))
		return (ls_sort_mtime(info, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 'f'))
		return (info);
	else
		return (ls_sort_name(info, ft_cisin(opt, 'r')));
}
