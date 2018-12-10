/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:50:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/10 20:04:10 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h> 
#include <dirent.h>
#include <sys/stat.h>

t_info	*lst_add(struct dirent *ptr, struct stat *info)
{
	t_info	*node;

	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	return (node);
}


int 	main(int ac, char **av)
{
	DIR				*ptr;
	struct dirent	*ret;
	struct stat		info;

	if (!(lst = malloc(sizeof(*lst))))
			return (0);
	if (!(ptr = opendir(av[--ac])))
		return (-1);
	while ((ret = readdir(ptr)))
	{
		stat(ret->d_name, &info);
		printf("%s\n", ret->d_name);
	}
	return (0);
}
