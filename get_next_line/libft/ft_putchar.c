/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:55:47 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 17:55:48 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
**		DESCRIPTION
**	Affiche le caractere c sur la sortie standard.
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}
