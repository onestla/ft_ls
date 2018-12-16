/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:59:01 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 19:22:13 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_simple_cmp(int a, int b, char *s1, char *s2)
{
	if (a == b)
		return (ft_strcmp(s1, s2) * -1);
	return (a - b);
}

t_info		*ls_sortrouter(t_info *info, char *opt)
{
	if (ft_cisin(opt, 'S'))
		return (ls_sort_size(info, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			return (ls_sort_ctime(info, ft_cisin(opt, 'r')));
		else if (ft_cisin(opt, 'u'))
			return (ls_sort_atime(info, ft_cisin(opt, 'r')));
		return (ls_sort_mtime(info, ft_cisin(opt, 'r')));
	}
	else if (ft_cisin(opt, 'f'))
		return (info);
	else
		return (ls_sort_name(info, ft_cisin(opt, 'r')));
}

t_path		*ls_psortrouter(t_path *path, char *opt)
{
	if (ft_cisin(opt, 'S'))
		return (ls_psort_size(path, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			return (ls_psort_ctime(path, ft_cisin(opt, 'r')));
		else if (ft_cisin(opt, 'u'))
			return (ls_psort_atime(path, ft_cisin(opt, 'r')));
		return (ls_psort_mtime(path, ft_cisin(opt, 'r')));
	}
	else if (ft_cisin(opt, 'f'))
		return (path);
	else
		return (ls_psort_name(path, ft_cisin(opt, 'r')));
}
