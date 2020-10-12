/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:10:04 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 16:10:05 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The isdigit() function tests for a decimal digit character.  Regard-
**	less of locale, this includes the following characters only:
**	-------------------------------------------------------------------------
**	``0''         ``1''         ``2''         ``3''         ``4''
**	``5''         ``6''         ``7''         ``8''         ``9''
**	-------------------------------------------------------------------------
**	The isnumber() function behaves similarly to isdigit(), but may rec-
**	ognize additional characters, depending on the current locale setting.
**	-------------------------------------------------------------------------
**	The value of the argument must be representable as an unsigned char
**	or the value of EOF.
**		RETURN VALUES
**	The isdigit() and isnumber() functions return zero if the character
**	tests false and return non-zero if the character tests true.
*/

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
