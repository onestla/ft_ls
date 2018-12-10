/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:58:54 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 16:44:31 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	while (s1[count] && s2[count])
	{
		if (s1[count] != s2[count])
			break ;
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
