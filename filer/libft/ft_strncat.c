/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:28:08 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/04 10:28:10 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strncat() functions append a copy of the null-terminated string s2
**	to the end of the null-terminated string s1, then add a terminating `\0'.
**	The string s1 must have sufficient space to hold the result.
**	-------------------------------------------------------------------------
**	The strncat() function appends not more than n characters from s2,
**	and then adds a terminating `\0'.
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap, as the behavior
**	is undefined.
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	The strncat() functions return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}
