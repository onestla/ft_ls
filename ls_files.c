/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:50:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/16 18:55:58 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*ls_folderin(DIR *ptr, char *path, char *opt)
{
	t_info			*info;
	struct dirent	*ret;
	char			*cpath;
	struct stat		vstat;

	info = NULL;
	while ((ret = readdir(ptr)))
	{
		if (ret->d_name[0] == '.' && !ft_cisin(opt, 'a') &&
				!ft_cisin(opt, 'A') && !ft_cisin(opt, 'f'))
			continue;
		if (ft_cisin(opt, 'A') && (!ft_strcmp("..", ret->d_name) ||
				!ft_strcmp(".", ret->d_name)))
			continue;
		cpath = ft_Sprintf("%s/%s", path, ret->d_name);
		lstat(cpath, &vstat);
		info = ls_infoadd(info, ret->d_name, vstat, ret->d_type);
		ft_strdel(&cpath);
	}
	if (ret)
		free(ret);
	return (info);
}

t_info		*ls_folder(char *path, char *opt)
{
	DIR				*ptr;
	t_info			*info;

	if (!(ptr = opendir(path)))
	{
		ft_dprintf(2, "ls: %s: %s\n", path, strerror(errno));
		return (NULL);
	}
	info = ls_folderin(ptr, path, opt);
	closedir(ptr);
	return (info);
}

t_info		*ls_file(char *file)
{
	struct stat	vstat;
	t_info		*info;

	info = NULL;
	lstat(file, &vstat);
	info = ls_infoadd(info, file, vstat, 0);
	return (info);
}

t_info		*ls_frouter(char *path, char *opt, int type)
{
	if (type == 1)
		return (ls_folder(path, opt));
	else
		return (ls_file(path));
}
