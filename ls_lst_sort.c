/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:31:40 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/11 18:57:19 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			if () // cmp fn to insert 
				swap_nodes(); // create fn to swap nodes 
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}
