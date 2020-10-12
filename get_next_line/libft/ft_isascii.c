/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:44:05 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 16:44:06 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The isascii() function tests for an ASCII character, which is any
**	character between 0 and octal 0177 inclusive.
*/

int		ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}
