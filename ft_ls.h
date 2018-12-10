/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:04:14 by apeyret           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/10 19:57:18 by apeyret          ###   ########.fr       */
=======
/*   Updated: 2018/12/10 20:05:36 by glavigno         ###   ########.fr       */
>>>>>>> 3bf5530fb0eb14394c16c0b1b70540da50674a73
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdlib.h>

typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	char			*name;
	struct s_info	*next;
}					t_info;				

t_path				*ls_pathadd(t_path *path, char *folder);
#endif
