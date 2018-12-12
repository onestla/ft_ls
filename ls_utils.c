/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:26:46 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/12 20:08:16 by apeyret          ###   ########.fr       */
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

void	print_rights(t_info *info)
{
	ft_printf("%c", (info->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IRGRP) ? 'r' : '-'); 
	ft_printf("%c", (info->stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_printf("%c", (info->stat.st_mode & S_IXOTH) ? 'x' : '-');
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


void	ls_sprint_rest(t_info *info)
{
	char			*tm;
	int				count;

	count = 0;
	tm = NULL;
	info->ligne[count++] = ft_Sprintf("%ld", info->stat.st_nlink);
	info->ligne[count++] = ft_Sprintf("%s", getpwuid(info->stat.st_uid)->pw_name);
	info->ligne[count++] = ft_Sprintf("%s", getgrgid(info->stat.st_gid)->gr_name);
	if (S_ISCHR(info->stat.st_mode) || S_ISBLK(info->stat.st_mode))
	{
		info->ligne[count++] = ft_Sprintf("%u,", major(info->stat.st_rdev));
		info->ligne[count++] = ft_Sprintf("%u", minor(info->stat.st_rdev));
	}
	else
	{
		info->ligne[count++] = ft_Sprintf(" ");
		info->ligne[count++] = ft_Sprintf("%lld", info->stat.st_size);
	}
	tm = ctime(&info->stat.st_mtime);
	tm[ft_strlen(tm) - 1] = '\0';
	info->ligne[count++] = ft_Sprintf("%.12s %s\n", tm + 4, info->name);
	info->ligne[count] = NULL;
}
