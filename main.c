/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:38:33 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 17:03:43 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_illegalopt(char illegal)
{
	ft_printf("ls: illegal option -- %c\n", illegal);
	ft_exit("usage: ls [-ARSTacfglrtu1] [file ...]", 1);
}

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
			if (!av[count][counta])
				path = ls_pathadd(path, av[count]);
			while (av[count][counta])
			{
				if (!ft_cisin("ARSTacfglrtu1", av[count][counta]))
					ls_illegalopt(av[count][counta]);
				else if (!ft_cisin(opt, av[count][counta]))
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

void	ls_ls(char *path, int type, char *opt, int count)
{
	t_info		*info;

	if (count && type != 2)
		ft_printf("%s:\n", path);
	info = ls_frouter(path, opt, type);
	info = ls_sortrouter(info, opt);
	ls_router(opt, info, path, type);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4 && ft_strcmp(".", info->name) &&
				ft_strcmp("..", info->name))
		{
			ft_printf("\n");
			ls_ls(ft_Sprintf("%s/%s", path, info->name), 1, opt, count + 1);
		}
		info = ls_infodel(info);
	}
	ls_infosdel(info);
	ft_strdel(&path);
}

void	ls_main(t_path *path, char *opt)
{
	int			count;
	int			i;
	t_path		*tmp;

	count = 0;
	i = 0;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 2)
			ls_ls(tmp->path, tmp->error, opt, count++);
		tmp = tmp->next;
	}
	count = ls_pathlen(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 1)
		{
			if (count > 0)
				(i++) ? ft_printf("\n") : 0;
			ls_ls(tmp->path, tmp->error, opt, count++);
		}
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_path		*path;
	char		*opt;

	path = NULL;
	if (!(opt = ft_strnew(13)))
		return (1);
	av++;
	if (!(path = ls_options(ac, av, path, opt)))
		path = ls_pathadd(path, ".");
	path = ls_psortrouter(path, opt);
	ls_main(path, opt);
	ls_pathdel(path);
	ft_strdel(&opt);
	return (0);
}
