/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:04:14 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/13 17:48:25 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <string.h>

typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	char			*name;
	unsigned char	type;
	struct stat		stat;
	
	char			*ligne[8];
	int				len[8];

	struct s_info	*next;
	struct s_info	*prev;
}					t_info;

t_info				*ls_files(char *path, char *opt);
t_path				*ls_pathadd(t_path *path, char *folder);
t_info				*ls_infoadd(t_info *info, char *name, struct stat stat, unsigned char type);
void				ls_router(char *opt, t_info *info);
void				print_filetype(t_info *info);
void				print_rights(t_info *info);
void				ls_sprint_rest(t_info *info);
t_info				*ls_sort_mtime(t_info *info, int rev);
t_info				*ls_sort_name(t_info *info, int rev);
t_info				*ls_sort_size(t_info *info, int rev);
int					n_blocks(t_info *info);
void				ls_infoswap(t_info *a, t_info *b);
t_info				*ls_sortrouter(t_info *info, char *opt);

#endif
