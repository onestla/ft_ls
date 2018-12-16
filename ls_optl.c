/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:26:46 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/16 18:58:15 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_filetype(t_info *info)
{
	S_ISBLK(info->stat.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR(info->stat.st_mode) ? ft_putchar('c') : 0;
	S_ISDIR(info->stat.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(info->stat.st_mode) ? ft_putchar('l') : 0;
	S_ISFIFO(info->stat.st_mode) ? ft_putchar('p') : 0;
	S_ISSOCK(info->stat.st_mode) ? ft_putchar('s') : 0;
	S_ISREG(info->stat.st_mode) ? ft_putchar('-') : 0;
}

void	ls_print_rights(t_info *info, char *path)
{
	char			buf[1024];
	ssize_t			len;

	ft_putchar((info->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((info->stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((info->stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((info->stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((info->stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((info->stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((info->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((info->stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((info->stat.st_mode & S_IXOTH) ? 'x' : '-');
	if ((len = listxattr(ft_Sprintf("%s/%s", path, info->name), buf,
		sizeof(buf) - 1, 0)) > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
}

void	ls_print_date(t_info *info, char *opt, int *count)
{
	time_t			tme;
	char			*tm;

	tme = time(NULL);
	if (ft_cisin(opt, 'u'))
		tm = ctime(&info->stat.st_atime);
	else if (ft_cisin(opt, 'c'))
		tm = ctime(&info->stat.st_ctime);
	else
		tm = ctime(&info->stat.st_mtime);
	tm[ft_strlen(tm) - 1] = '\0';
	if (tme - info->stat.st_mtime > SIX_MONTHS || info->stat.st_mtime > tme)
	{
		if (!ft_cisin(opt, 'T'))
			info->ligne[(*count)++] = ft_Sprintf("%.6s  %.4s", tm + 4, tm + 20);
		else
			info->ligne[(*count)++] = ft_Sprintf("%s", tm + 4);
	}
	else
	{
		if (!ft_cisin(opt, 'T'))
			info->ligne[(*count)++] = ft_Sprintf("%.12s", tm + 4);
		else
			info->ligne[(*count)++] = ft_Sprintf("%s", tm + 4);
	}
}

char	*ls_relink(t_info *info, char *path, int type)
{
	char		buf[1024];
	char		*tmp;
	ssize_t		len;

	if (type == 2)
		tmp = ft_strdup(path);
	else
		tmp = ft_Sprintf("%s/%s", path, info->name);
	if ((len = readlink(tmp, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_strdel(&tmp);
	return (ft_Sprintf("%s -> %s", info->name, buf));
}

void	ls_sprint_rest(t_info *info, char *path, char *opt, int type)
{
	int			i;

	i = 0;
	info->ligne[i++] = ft_Sprintf("%ld", info->stat.st_nlink);
	if (!ft_cisin(opt, 'g') && getpwuid(info->stat.st_uid))
		info->ligne[i++] = ft_Sprintf("%s",
			getpwuid(info->stat.st_uid)->pw_name);
	else if (!ft_cisin(opt, 'g'))
		info->ligne[i++] = ft_Sprintf("%d", info->stat.st_uid);
	info->ligne[i++] = ft_Sprintf(" %s", getgrgid(info->stat.st_gid)->gr_name);
	if (S_ISCHR(info->stat.st_mode) || S_ISBLK(info->stat.st_mode))
		info->ligne[i++] = ft_Sprintf("%u, %3u", major(info->stat.st_rdev),
			minor(info->stat.st_rdev));
	else
		info->ligne[i++] = ft_Sprintf(" %lld", info->stat.st_size);
	ls_print_date(info, opt, &i);
	if (S_ISLNK(info->stat.st_mode))
		info->ligne[i++] = ls_relink(info, path, type);
	else
		info->ligne[i++] = ft_Sprintf("%s", info->name);
	info->ligne[i] = NULL;
}
