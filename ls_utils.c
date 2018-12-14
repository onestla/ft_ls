/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:26:46 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/14 11:43:15 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		n_blocks(t_info *info)
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

void	print_filetype(t_info *info)
{
	S_ISBLK(info->stat.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR(info->stat.st_mode) ? ft_putchar('c') : 0;
	S_ISDIR(info->stat.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(info->stat.st_mode) ? ft_putchar('l') : 0;
	S_ISFIFO(info->stat.st_mode) ? ft_putchar('p') : 0;
	S_ISSOCK(info->stat.st_mode) ? ft_putchar('s') : 0;
	S_ISREG(info->stat.st_mode) ? ft_putchar('-') : 0;
}

void	print_rights(t_info *info, char *path)
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
	if ((len = listxattr(ft_Sprintf("%s/%s", path, info->name), buf, sizeof(buf) - 1, 0)) > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
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
	if (tme - info->stat.st_mtime > SIX_MONTHS)
		info->ligne[(*count)++] = ft_Sprintf("%.6s  %.4s", tm + 4, tm + 20);
	else
		info->ligne[(*count)++] = ft_Sprintf("%.12s", tm + 4);
}

void	ls_sprint_rest(t_info *info, char *path, char *opt)
{
	int				count;
	char			buf[1024];
	ssize_t			len;

	count = 0;
	info->ligne[count++] = ft_Sprintf("%ld", info->stat.st_nlink);
	if (!ft_cisin(opt, 'g'))
		info->ligne[count++] = ft_Sprintf(" %s", getpwuid(info->stat.st_uid)->pw_name);
	info->ligne[count++] = ft_Sprintf(" %s", getgrgid(info->stat.st_gid)->gr_name);
	if (S_ISCHR(info->stat.st_mode) || S_ISBLK(info->stat.st_mode))
		info->ligne[count++] = ft_Sprintf("%u, %3u", major(info->stat.st_rdev), minor(info->stat.st_rdev));
	else
		info->ligne[count++] = ft_Sprintf(" %lld", info->stat.st_size);
	ls_print_date(info, opt, &count);
	if (S_ISLNK(info->stat.st_mode))
	{
		if ((len = readlink(ft_Sprintf("%s/%s", path, info->name), buf, sizeof(buf) - 1)) != -1)
			buf[len] = '\0';
		info->ligne[count++] = ft_Sprintf("%s -> %s", info->name, buf);
	}
	else 
		info->ligne[count++] = ft_Sprintf("%s", info->name);
	info->ligne[count] = NULL;
}
