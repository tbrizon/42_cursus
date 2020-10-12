/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:53:12 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 15:53:33 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
**		DESCRIPTION
**	Write a string s until size
*/

void	ft_putnstr(char *s, size_t size)
{
	if (s)
		write(1, s, size);
	else
		ft_putstr("(null)");
}
