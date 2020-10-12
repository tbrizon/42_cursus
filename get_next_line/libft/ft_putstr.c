/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:56:29 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 17:56:30 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**		DESCRIPTION
**	Affiche la chaine s sur la sortie standard.
*/

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}
