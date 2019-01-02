/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:38:33 by apeyret           #+#    #+#             */
/*   Updated: 2019/01/02 16:14:22 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_optt(char *exec, char *s, char *opt)
{
	int count;

	count = 1;
	while (s[count])
	{
		if (!ft_cisin("ARSTacfglrtu1", s[count]))
		{
			ft_printf("%s: illegal option -- %c\n", exec, s[count]);
			ft_exit("usage: ls [-ARSTacfglrtu1] [file ...]", 1);
		}
		else if (!ft_cisin(opt, s[count]))
			ft_strncat(opt, &(s[count]), 1);
		count++;
	}
}

t_path	*ls_options(int ac, char **av, t_path *path, char *opt)
{
	int			count;

	count = 1;
	while (count < ac)
	{
		if (!ft_strcmp(av[count], "--"))
		{
			count++;
			break ;
		}
		else if (av[count][0] == '-')
			ls_optt(av[0], av[count], opt);
		else
			break ;
		count++;
	}
	while (count < ac)
	{
		path = ls_pathadd(path, av[count], opt);
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
			if (!ft_strcmp("/", path))
				ls_ls(ft_zprintf("%s%s", path, info->name), 1, opt, count + 1);
			else
				ls_ls(ft_zprintf("%s/%s", path, info->name), 1, opt, count + 1);
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
		(tmp->error == 2) ? ls_ls(tmp->path, tmp->error, opt, count++) : 0;
		(tmp->error == 2) ? i++ : 0;
		tmp = tmp->next;
	}
	count = ls_pathlen(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 1)
		{
			(i) ? ft_printf("\n") : 0;
			i = 1;
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
	if (!(path = ls_options(ac, av, path, opt)))
		path = ls_pathadd(path, ".", opt);
	path = ls_psortrouter(path, opt);
	ls_main(path, opt);
	ls_pathdel(path);
	ft_strdel(&opt);
	return (0);
}
