/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:31:40 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/12 09:22:52 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		simple_cmp(int a, int b, char *s1, char *s2)
{
	if ((a - a % 60) ==  (b - b % 60))
		return (-1 * ft_strcmp(s1, s2));
	return (a - b);
}

void	swap_nodes(t_info *a, t_info *b)
{
	char		*str_tmp;
	struct stat	struct_tmp;

	str_tmp = a->name;
	a->name = b->name;
	b->name = str_tmp;
	struct_tmp = a->stat;
	a->stat = b->stat;
	b->stat = struct_tmp;
}

t_info		*sort_by_mtime(t_info *info)
{
	t_info	*begin;
	t_info	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if (simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime, info->name, tmp->name) < 0) // cmp fn to insert 
				swap_nodes(info, tmp); // create fn to swap nodes' content 
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}
