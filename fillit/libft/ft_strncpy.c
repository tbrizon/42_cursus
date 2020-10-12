/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:12:31 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/03 17:12:33 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strncpy() functions copy at most n characters from src into dst.
**	If src is less than n characters long, the remainder of dst is filled
**	with `\0' characters.  Otherwise, dst is not terminated.
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap,
**	as the behavior is undefined.
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	The strncpy() functions return dst.
*/

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (n--)
		if (*src == '\0')
			*tmp++ = 0;
		else
			*tmp++ = *src++;
	return (dest);
}
