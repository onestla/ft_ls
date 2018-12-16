/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_psort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:11:53 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 19:11:57 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path		*ls_psort_atime(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat	tstat;
	struct stat	pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->path, &pstat);
			lstat(tmp->path, &tstat);
			if ((ls_simple_cmp(pstat.st_atime, tstat.st_atime, path->path,
						tmp->path) < 0 && !rev) ||
					(ls_simple_cmp(pstat.st_atime, tstat.st_atime, path->path,
						tmp->path) > 0 && rev))
				ls_pathswap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

t_path		*ls_psort_ctime(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat	tstat;
	struct stat	pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->path, &pstat);
			lstat(tmp->path, &tstat);
			if ((ls_simple_cmp(pstat.st_ctime, tstat.st_ctime, path->path,
						tmp->path) < 0 && !rev) ||
					(ls_simple_cmp(pstat.st_ctime, tstat.st_ctime, path->path,
						tmp->path) > 0 && rev))
				ls_pathswap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

t_path		*ls_psort_mtime(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat tstat;
	struct stat pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->path, &pstat);
			lstat(tmp->path, &tstat);
			if ((ls_simple_cmp(pstat.st_mtime, tstat.st_mtime, path->path,
						tmp->path) < 0 && !rev) ||
					(ls_simple_cmp(pstat.st_mtime, tstat.st_mtime, path->path,
						tmp->path) > 0 && rev))
				ls_pathswap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

t_path		*ls_psort_name(t_path *path, int rev)
{
	t_path	*begin;
	t_path	*tmp;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if ((ft_strcmp(path->path, tmp->path) > 0 && !rev) ||
				(ft_strcmp(path->path, tmp->path) < 0 && rev))
				ls_pathswap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

t_path		*ls_psort_size(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat tstat;
	struct stat pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->path, &pstat);
			lstat(tmp->path, &tstat);
			if ((ls_simple_cmp(pstat.st_size, tstat.st_size, path->path,
						tmp->path) < 0 && !rev) ||
					(ls_simple_cmp(pstat.st_size, tstat.st_size, path->path,
						tmp->path) > 0 && rev))
				ls_pathswap(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}
