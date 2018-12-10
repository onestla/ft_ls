/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:28:51 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/08 17:05:20 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
