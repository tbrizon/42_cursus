/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:20:52 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 18:20:53 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Affiche l'entier n sur la sortie standard.
*/

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
