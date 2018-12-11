/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:50:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/11 11:55:04 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info 	*ls_files(char *path, char *opt)
{
	t_info			*info;
	DIR				*ptr;
	struct dirent	*ret;
	struct stat		vstat;

	info = NULL;
	if (!(ptr = opendir(path)))
		ft_exit("Failed to open stream: No such file or directory", 1);
	while ((ret = readdir(ptr)))
	{
		if (ret->d_name[0]  == '.' && !ft_cisin(opt, 'a'))
			continue;
		stat(ret->d_name, &vstat);
		info = ls_infoadd(info, ret->d_name, vstat);
	}
	closedir(ptr);
	return (info);
}
