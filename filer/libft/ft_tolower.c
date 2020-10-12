/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:23:27 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 17:23:28 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The tolower() function converts an upper-case letter to the corresponding
**	lower-case letter.  The argument must be representable as an unsigned char
**	or the value of EOF.
**	-------------------------------------------------------------------------
**	Although the tolower() function uses the current locale, the tolower_l()
**	function may be passed a locale directly. See xlocale(3) for more
**	information.
**		RETURN VALUES
**	If the argument is an upper-case letter, the tolower() function returns
**	the corresponding lower-case letter if there is one; otherwise, the
**	argument is returned unchanged.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
