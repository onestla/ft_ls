/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:38:33 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/14 18:09:38 by apeyret          ###   ########.fr       */
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
				if (!ft_cisin("ARSTacfglrtu1", av[count][counta]))
				{
					ft_printf("ls: illegal option -- %c\n", av[count][counta]);
					ft_printf("usage: ls [-ARSTacfglrtu1] [file ...]\n");
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

void	ls_infodel(t_info *info)
{
	int		count;

	if (!info)
		return ;
	count = 0;
	ft_strdel(&(info->name));
	while (info->ligne[count])
	{
		ft_strdel(&(info->ligne[count]));
		count++;
	}
	free(info);
	info = NULL;
}

void	ls_ls(char *path, int type, char *opt, int count)
{
	t_info		*info;
	t_info		*itmp;

	if (count && type != 2)
		ft_printf("%s:\n", path);
	info = ls_frouter(path, opt, type);
	info = ls_sortrouter(info, opt);
	ls_router(opt, info, path, type);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4 && ft_strcmp(".", info->name) && ft_strcmp("..", info->name))
		{
			ft_printf("\n");
			ls_ls(ft_Sprintf("%s/%s", path, info->name), 1,  opt, count + 1);
		}
		itmp = info;
		info = info->next;
		ls_infodel(itmp);
	}
	ft_strdel(&path);
	while (info)
	{
		itmp = info;
		info = info->next;
		ls_infodel(itmp);
	}
}

int		main(int ac, char **av)
{
	t_path		*path;
	t_path		*tmp;
	char		*opt;
	int			count;

	path = NULL;
	count = 0;
	if (!(opt = ft_strnew(13)))
		return (1);
	av++;
	if (!(path = ls_options(ac, av, path, opt)))
		path = ls_pathadd(path, ".");
	path = ls_psortrouter(path, opt);
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 2)
			ls_ls(tmp->path, tmp->error,  opt, count++);
		tmp = tmp->next;
	}
	count = ls_pathlen(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 1)
		{
			if (count != 0)
				ft_printf("\n");
			ls_ls(tmp->path, tmp->error,  opt, count++);
		}
		tmp = tmp->next;
	}
	return (0);
}
