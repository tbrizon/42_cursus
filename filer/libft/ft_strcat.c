/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:04:58 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/03 18:04:59 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strcat() functions append a copy of the null-terminated string s2
**	to the end of the null-terminated string s1, then add a terminating `\0'.
**	The string s1 must have sufficient space to hold the result.
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap, as the behavior
**	is undefined.
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	The strcat() functions return the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}
