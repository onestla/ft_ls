/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:04:14 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/10 22:19:28 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	char			*name;
	struct stat		stat;
	struct s_info	*next;
}					t_info;				

t_info				*ls_files(char *path, char *opt);
t_path				*ls_pathadd(t_path *path, char *folder);
t_info				*ls_infoadd(t_info *info, char *name, struct stat stat);
void				ls_router(char *opt, t_info *info);
#endif
