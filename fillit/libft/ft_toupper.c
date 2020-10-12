/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:08:42 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 17:08:43 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The toupper() function converts a lower-case letter to the corresponding
**	upper-case letter.  The argument must be representable as an unsigned char
**	or the value of EOF.
**	-------------------------------------------------------------------------
**	Although the toupper() function uses the current locale, the
**	toupper_l() function may be passed a locale directly. See xlocale(3)
**	for more information.
**		RETURN VALUES
**	If the argument is a lower-case letter, the toupper() function
**	returns the corresponding upper-case letter if there is one; otherwise,
**	the argument is returned unchanged.
*/

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
