/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:56:13 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/16 19:16:30 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_isfolder(char *path)
{
	char	*error;
	DIR		*ptr;

	if (!(ptr = opendir(path)))
	{
		error = strerror(errno);
		if (!ft_strcmp("Not a directory", error))
			return (0);
		ft_dprintf(2, "ls: %s: %s\n", path, error);
		return (-1);
	}
	closedir(ptr);
	return (1);
}

int			ls_fcheck(char *path)
{
	int ret;

	ret = 0;
	if ((ret = ls_isfolder(path)) != 0)
		return (ret);
	return (2);
}
