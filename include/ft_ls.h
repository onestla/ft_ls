/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:04:14 by apeyret           #+#    #+#             */
/*   Updated: 2019/01/04 17:04:55 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <string.h>

# define SIX_MONTHS 15552000

typedef struct		s_path
{
	char			*path;
	int				error;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	char			*name;
	unsigned char	type;
	struct stat		stat;
	char			*ligne[9];
	int				len[8];
	struct s_info	*next;
	struct s_info	*prev;
}					t_info;

void				ls_router(char *opt, t_info *info, char *path, int type);
void				ls_print_filetype(t_info *info);
void				ls_pathswap(t_path *a, t_path *b);
int					ls_simple_cmp(int a, int b, char *s1, char *s2);
void				ls_print_rights(t_info *info, char *path);
void				ls_sprint_rest(t_info *info, char *path, char *opt,
					int type);
int					ls_n_blocks(t_info *info);
void				ls_infoswap(t_info *a, t_info *b);
int					ls_pathlen(t_path *path);
time_t				get_diff(time_t t, char *opt, t_info *info);

t_info				*ls_frouter(char *path, char *opt, int type);
int					ls_fcheck(char *path, char *opt);
t_path				*ls_pathadd(t_path *path, char *folder, char *opt);
t_info				*ls_infoadd(t_info *info, char *name, struct stat stat,
					unsigned char type);

t_info				*ls_infodel(t_info *info);
void				ls_infosdel(t_info *info);
void				ls_pathdel(t_path *path);

t_info				*ls_sort_atime(t_info *info, int rev);
t_info				*ls_sort_ctime(t_info *info, int rev);
t_info				*ls_sort_mtime(t_info *info, int rev);
t_info				*ls_sort_name(t_info *info, int rev);
t_info				*ls_sort_size(t_info *info, int rev);
t_path				*ls_psort_atime(t_path *path, int rev);
t_path				*ls_psort_ctime(t_path *path, int rev);
t_path				*ls_psort_mtime(t_path *path, int rev);
t_path				*ls_psort_name(t_path *path, int rev);
t_path				*ls_psort_size(t_path *path, int rev);
t_info				*ls_sortrouter(t_info *info, char *opt);
t_path				*ls_psortrouter(t_path *path, char *opt);
int					*ls_infolen_l(t_info *info);

#endif
