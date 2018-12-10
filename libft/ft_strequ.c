/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:04:36 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/11 15:47:32 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int	count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[count] || s2[count])
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}
