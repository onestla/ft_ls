/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:28:55 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/10 09:20:27 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_cpy_spec(t_printf *lst, char *tmp)
{
	lst->opt.tmp = tmp;
	if (lst->type == 'c')
	{
		pf_options("*", lst->opt);
		ft_replace(tmp, '*', lst->var[0], lst->len);
	}
	else
		pf_options(lst->var, lst->opt);
	if (lst->type == 'x' || lst->type == 'p')
		ft_strlower(lst->opt.tmp);
}

char	*ret(t_printf *lst, int len)
{
	char	*s;
	char	*tmp;

	if (!(s = ft_strnew(len)))
		return (NULL);
	tmp = s;
	while (lst)
	{
		if (!lst->var)
			return (s);
		if (!lst->needconv)
			ft_strcpy(tmp, lst->var);
		else
			pf_cpy_spec(lst, tmp);
		tmp += lst->len;
		lst = lst->next;
	}
	return (s);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	va_list		ap;
	int			len;
	char		*s;

	lst = parser(format);
	if (!lst)
		return (0);
	va_start(ap, format);
	pf_router(lst, ap);
	len = lenall(lst);
	s = ret(lst, len);
	write(1, s, len);
	free(s);
	pf_prdel(lst);
	return (len);
}
