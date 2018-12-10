/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:43:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/10 17:53:03 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		tmp = (*alst)->next;
		del((**alst).content, (**alst).content_size);
		free(*alst);
		*alst = tmp;
	}
}
