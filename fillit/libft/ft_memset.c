/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:07:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/02 17:07:50 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memset() function writes len bytes of value c (converted to an
**	unsigned char) to the string b.
**		RETURN VALUES
**	The memset() function returns its first argument.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
