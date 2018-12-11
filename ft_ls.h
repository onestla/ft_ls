/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:04:14 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/11 16:55:28 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

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
void				print_filetype(t_info *info);
void				print_rights(t_info *info);
void				print_rest(t_info *info);
int					n_blocks(t_info *info);

#endif
