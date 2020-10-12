/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:54:40 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/09 11:54:41 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une chaine de caracteres terminee
**	par un ’\0’ representant l’entier n.
**	Si l'allocation echoue, la fonction renvoie NULL.
*/

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	while (n)
	{
		len--;
		s[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
