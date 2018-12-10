/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:16:27 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/10 20:06:25 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path	*ls_pathadd(t_path *path, char *folder)
{
	t_path *end;
	t_path *tmp;

	if (!(end = malloc(sizeof(t_path))))
		return (NULL);
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