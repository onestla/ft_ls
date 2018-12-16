/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:16:27 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 17:41:09 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path	*ls_pathadd(t_path *path, char *folder)
{
	t_path *end;
	t_path *tmp;

	if (!(end = malloc(sizeof(t_path))))
		return (NULL);
	end->error = ls_fcheck(folder);
	end->path = ft_strdup(folder);
	end->next = NULL;
	if (!path)
		return (end);
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	return (path);
}

t_info	*ls_infoadd(t_info *info, char *name, struct stat vstat,
	unsigned char type)
{
	t_info *end;
	t_info *tmp;

	if (!(end = malloc(sizeof(t_info))))
		return (NULL);
	end->name = ft_strdup(name);
	end->type = type;
	end->ligne[0] = NULL;
	end->stat = vstat;
	end->next = NULL;
	if (!info)
		return (end);
	tmp = info;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	return (info);
}

void	ls_infoswap(t_info *a, t_info *b)
{
	struct stat		tmps;
	char			*tmpn;
	unsigned char	tmpt;

	tmpn = a->name;
	tmpt = a->type;
	tmps = a->stat;
	a->name = b->name;
	a->type = b->type;
	a->stat = b->stat;
	b->name = tmpn;
	b->type = tmpt;
	b->stat = tmps;
}

void	ls_pathswap(t_path *a, t_path *b)
{
	char		*tmpp;
	int			tmpe;

	tmpp = a->path;
	tmpe = a->error;
	a->path = b->path;
	a->error = b->error;
	b->path = tmpp;
	b->error = tmpe;
}

int		ls_pathlen(t_path *path)
{
	int count;

	count = 0;
	while (path)
	{
		count++;
		path = path->next;
	}
	return (count);
}
