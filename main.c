/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:38:33 by apeyret           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/13 17:03:37 by glavigno         ###   ########.fr       */
=======
/*   Updated: 2018/12/13 17:25:02 by apeyret          ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
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
				if (!ft_cisin("ARaflrt", av[count][counta]))
				{
					ft_printf("ls: illegal option -- %c\n", av[count][counta]);
					ft_printf("usage: ls [-ARalrt] [file ...]\n");
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
		info = ls_sort_mtime(info, ft_cisin(opt, 'r'));
	else if (!ft_cisin(opt, 'f'))
		info = ls_sort_name(info, ft_cisin(opt, 'r'));
	ls_router(opt, info, path);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4 && ft_strcmp(".", info->name) && ft_strcmp("..", info->name))
		{
			ft_printf("\n");
			ls_ls(ft_Sprintf("%s/%s", tmp, info->name),  opt, count + 1);
		}
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
