/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:42:28 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/12 12:34:57 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_addlast(t_list *lst, t_list *add)
{
	t_list		*tmp;

	tmp = lst;
	add->next = NULL;
	if (tmp == NULL)
		return (add);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = ft_addlast(tmp, f(lst));
		lst = lst->next;
	}
	return (tmp);
}
