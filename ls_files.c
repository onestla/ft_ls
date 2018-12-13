/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:50:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/13 17:25:27 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info 	*ls_files(char *path, char *opt)
{
	t_info			*info;
	char			*cpath;
	DIR				*ptr;
	struct dirent	*ret;
	struct stat		vstat;

	info = NULL;
	if (!(ptr = opendir(path)))
	{
		ft_dprintf(2, "ls: %s: %s\n", path, strerror(errno));
		return (NULL);
	}
	while ((ret = readdir(ptr)))
	{
		if (ret->d_name[0]  == '.' && !ft_cisin(opt, 'a') && !ft_cisin(opt, 'A') && !ft_cisin(opt, 'f'))
			continue;
		if (ft_cisin(opt, 'A') && (!ft_strcmp("..", ret->d_name) || !ft_strcmp(".", ret->d_name)))
			continue;
		cpath = ft_Sprintf("%s/%s", path, ret->d_name);
		stat(cpath, &vstat);
		info = ls_infoadd(info, ret->d_name, vstat, ret->d_type);
		ft_strdel(&cpath);
	}
	closedir(ptr);
	return (info);
}
