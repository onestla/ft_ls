/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:38:33 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/12 20:57:52 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path	*ls_options(int ac, char **av, t_path *path, char *opt)
{
	int			count;
	int			counta;

	count = 0;
	while (count < ac - 1)
	{
		if (av[count][0] == '-')
		{
			counta = 1;
			while (av[count][counta])
			{
				if (!ft_cisin("lRart", av[count][counta]))
				{
					ft_printf("ls: illegal option -- %c\n", av[count][counta]);
					ft_printf("usage: ls [-Ralrt] [file ...]\n");
					exit(1);
				}
				if (!ft_cisin(opt, av[count][counta]))
					ft_strncat(opt, &(av[count][counta]), 1);
				counta++;
			}
		}
		else
			path = ls_pathadd(path, av[count]);
		count++;
	}
	return (path);
}

void	ls_ls(char *path, char *opt, int count)
{
	t_info		*info;
	char		*tmp;

	tmp = path;
	if (count)
		ft_printf("%s:\n", path);
	if (!(info = ls_files(tmp, opt)))
		return ;
	if (ft_cisin(opt, 't'))
		info = ls_sort_mtime(info);
	else
		info = ls_sort_name(info);
	ls_router(opt, info);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4)
			ft_printf("\n");
		if (info->type == 4)
			ls_ls(ft_Sprintf("%s/%s", tmp, info->name),  opt, count + 1);
		info = info->next;
	}
}

int		main(int ac, char **av)
{
	t_path		*path;
	char		*opt;
	int			count;

	path = NULL;
	count = 0;
	if (!(opt = ft_strnew(5)))
		return (1);
	av++;
	if (!(path = ls_options(ac, av, path, opt)))
		path = ls_pathadd(path, ".");
	while (path)
	{
		ls_ls(path->path, opt, count++);
		path = path->next;
	}
	return (0);
}
