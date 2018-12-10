/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:20:13 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 15:44:54 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	count;

	count = 0;
	if (!s || !f)
		return ;
	while (s[count])
	{
		f(count, &s[count]);
		count++;
	}
}
