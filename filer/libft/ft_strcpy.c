/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:13:17 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 18:44:20 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strcpy() functions copy the string src to dst
**	(including the terminating `\0' character).
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap,
**	as the behavior is undefined.
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	The strcpy() functions return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
