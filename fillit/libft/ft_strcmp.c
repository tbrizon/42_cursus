/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:33:45 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/04 17:33:47 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strcmp() functions lexicographically compare the null-terminated
**	strings s1 and s2.
**		RETURN VALUES
**	The strncmp() functions return an integer greater than, equal to, or less
**	than 0, according as the string s1 is greater than, equal to, or less than
**	the string s2.  The comparison is done using unsigned characters,
**	so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
