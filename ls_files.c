/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:50:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/14 16:39:36 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info 	*ls_folder(char *path, char *opt)
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
		lstat(cpath, &vstat);
		info = ls_infoadd(info, ret->d_name, vstat, ret->d_type);
		ft_strdel(&cpath);
	}
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

int		ls_isfolder(char *path)
{
	char *error;

	if (!opendir(path))
	{
		error = strerror(errno);
		if (!ft_strcmp("Not a directory", error))
			return (0);
		ft_dprintf(2, "ls: %s: %s\n", path, error);
		return (-1);
	}
	return (1);
}

int		ls_fcheck(char *path)
{
	int ret;

	ret = 0;
	if ((ret = ls_isfolder(path)) != 0)
		return (ret);
	return (2);
}

t_info		*ls_frouter(char *path, char *opt, int type)
{
	if (type == 1)
		return (ls_folder(path, opt));
	else
		return (ls_file(path));
}
