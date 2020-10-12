/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:12:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/10 11:12:51 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Prend un int n et retourne sa longueur len
*/

int		ft_intlen(int n)
{
	int		len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
