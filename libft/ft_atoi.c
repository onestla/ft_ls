/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:59 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/09 16:57:28 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int count;
	int	signe;
	int	res;

	res = 0;
	count = 0;
	signe = 1;
	while ((str[count] == ' ') || (str[count] == '\t') || (str[count] == '\n')
		|| (str[count] == '\v') || (str[count] == '\f') || (str[count] == '\r'))
		count++;
	if (str[count] == '-')
	{
		signe = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = res * 10 + str[count] - '0';
		count++;
	}
	return (res * signe);
}
