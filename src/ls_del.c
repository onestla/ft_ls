/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:16:54 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/14 19:19:34 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*ls_infodel(t_info *info)
{
	int		count;
	t_info	*tmp;

	if (!info)
		return (NULL);
	tmp = info->next;
	count = 0;
	ft_strdel(&(info->name));
	while (info->ligne[count])
	{
		ft_strdel(&(info->ligne[count]));
		count++;
	}
	free(info);
	info = NULL;
	return (tmp);
}

void	ls_infosdel(t_info *info)
{
	while (info)
		info = ls_infodel(info);
}

void	ls_pathdel(t_path *path)
{
	t_path *tmp;

	while (path)
	{
		if (path->error == -1)
			ft_strdel(&(path->path));
		tmp = path;
		path = path->next;
		free(tmp);
	}
}
