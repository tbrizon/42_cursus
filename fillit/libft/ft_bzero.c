/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:00:19 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/02 18:00:21 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The bzero() function writes n zeroed bytes to the string s.
**	If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}
