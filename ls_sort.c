/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:31:40 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/12 14:25:49 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		simple_cmp(int a, int b, char *s1, char *s2)
{
	if (a == b)
		return (ft_strcmp(s1, s2) * -1);
	return (a - b);
}

void	swap_nodes(t_info *a, t_info *b)
{
	t_info *c;

	c = a->next;
	a->next = b->next;
	b->next = c;
	c = a->prev;
	a->prev = b->prev;
	b->prev = c;
}

t_info		*ls_sort_mtime(t_info *info)
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
			if (simple_cmp(info->stat.st_mtime, tmp->stat.st_mtime, info->name, tmp->name) < 0)
				swap_nodes(info, tmp); 
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}

t_info		*ls_sort_name(t_info *info)
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
			if (ft_strcmp(info->name, tmp->name) > 0)  
				swap_nodes(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}
