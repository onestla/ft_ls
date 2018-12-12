/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:26:46 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/12 09:07:00 by glavigno         ###   ########.fr       */
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
	ft_printf("%c", S_ISBLK(info->stat.st_mode) ? 'b' : 0);
	ft_printf("%c", S_ISCHR(info->stat.st_mode) ? 'c' : 0);
	ft_printf("%c", S_ISDIR(info->stat.st_mode) ? 'd' : 0);
	ft_printf("%c", S_ISLNK(info->stat.st_mode) ? 'l' : 0);
	ft_printf("%c", S_ISFIFO(info->stat.st_mode) ? 'p' : 0);
	ft_printf("%c", S_ISSOCK(info->stat.st_mode) ? 's' : 0);
	ft_printf("%c", S_ISREG(info->stat.st_mode) ? '-' : 0);
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
	ft_putchar(' ');
}

void	print_rest(t_info *info)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*tm;

	ft_printf("%3ld", info->stat.st_nlink);
	pwd = getpwuid(info->stat.st_uid);
	ft_printf("%10s", pwd->pw_name);
	grp = getgrgid(info->stat.st_gid);
	ft_printf("%12s", grp->gr_name);
	ft_printf("%10lld", info->stat.st_size);
	tm = ctime(&info->stat.st_mtime);
	tm[ft_strlen(tm) - 1] = '\0';
	ft_putchar(' ');
	ft_printf("%s", tm + 4);
	ft_putchar(' ');
	ft_printf("%-s\n", info->name);
}
