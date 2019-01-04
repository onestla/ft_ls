/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optl01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:57:22 by apeyret           #+#    #+#             */
/*   Updated: 2019/01/04 17:08:42 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ls_infolen_l(t_info *info)
{
	t_info	*tmp;
	int		count;
	int		*len;

	count = 0;
	len = NULL;
	if (!(len = (int*)malloc(sizeof(int) * 9)))
		return (NULL);
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

int		ls_n_blocks(t_info *info)
{
	int		total;

	total = 0;
	while (info)
	{
		total += info->stat.st_blocks;
		info = info->next;
	}
	return (total);
}

int		ls_lnlink(t_info *info)
{
	int len;

	len = 0;
	while (info)
	{
		if (len < info->stat.st_nlink)
			len = info->stat.st_nlink;
		info = info->next;
	}
	return (ft_intlen(len));
}

time_t	get_diff(time_t t, char *opt, t_info *info)
{
	time_t	tmp;
	char	*tm;

	if (ft_cisin(opt, 'u'))
	{
		tm = ctime(&info->stat.st_atime);
		tmp = info->stat.st_atime;
	}
	else if (ft_cisin(opt, 'c'))
	{
		tm = ctime(&info->stat.st_ctime);
		tmp = info->stat.st_ctime;
	}
	else
	{
		tm = ctime(&info->stat.st_mtime);
		tmp = info->stat.st_mtime;
	}
	return (t - tmp);
}
