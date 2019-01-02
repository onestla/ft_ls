/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_optl01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:57:22 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 19:16:54 by apeyret          ###   ########.fr       */
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
